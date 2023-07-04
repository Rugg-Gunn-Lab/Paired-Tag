//
// Created by Chenxu Zhu on 6/29/18.
//

#include "reachtools.h"
#include "cxstring.h"


char str2char(string str);
int align_score(string str1, string str2);
string get_read_type(string typ);
string get_bc_number(string bc, int score); //, map<string, string> *bc_library);
string get_bc_number_4(string bc, int score); //, map<string, string> *bc_library);





/// Global functions

string reachtools:: extract_barcode(string seq){ //, map<string, string> bc_library){
	string umi = seq.substr(119,8);
	string bc1 = seq.substr(76,8);
	string bc2 = seq.substr(38,8);
	string bc3 = seq.substr(0,8);
	string typ = seq.substr(119,19);//dna reads:AGATGTGTATAAGAGACAG, rna reads: N8+T15
	string bc4 = seq.substr(114,5);

    int bc_align_score = 7;

    string bc_number1 = get_bc_number(bc1, bc_align_score);
    string bc_number2 = get_bc_number(bc2, bc_align_score);
    string bc_number3 = get_bc_number(bc3, bc_align_score);
    string bc_number4 = get_bc_number_4(bc4, 4);

    string type = get_read_type(typ);

    string read_id = type + ':' + bc_number1 + ':' + bc_number2 + ':' + bc_number3 + ':' + bc_number4 + ':' + umi;
    return(read_id);
}

void reachtools:: docking(string & read, string & quality){
    string model ="NNNNNNNNGTGGCCGATGTTTCGCATCGGCGTACGACTNNNNNNNNGGATTCGAGGAGCGTGTGCGAACTCAGACCNNNNNNNNATCCACGTGCTTGAGAGGCCAGAGCATTCGNNNNNNNNNNNNNNNNNNNNNNNN"; 
    //r04 linker
    //string bait;
    int score = 0;
    int cur_score = 0;
    for(int i = 8; i < 23; ++i){
        if(model.substr(i, 1) == read.substr(i, 1)) ++cur_score;
        if(model.substr(i, 1) == read.substr(i - 1, 1)) ++score;
    }
    if(score > cur_score){
        read = "N" + read;
        quality = "I" + quality;
        cur_score = score;
    }
    if(cur_score < 10){
        read = "Low Quality";
        return;
    }

    //r03 linker
    score = 0;
    cur_score = 0;
    for(int i = 23; i < 38; ++i){
        if(model.substr(i, 1) == read.substr(i, 1))++cur_score;
        if(model.substr(i, 1) == read.substr(i - 1, 1))++score;
    }
    if(score > cur_score){
        read = read.substr(0, 23) + "N" + read.substr(23, read.length()-23);
        quality = quality.substr(0, 23) + "I" + read.substr(23, quality.length()-23);
        cur_score = score;
    }
    if(cur_score < 9){
        read = "Low Quality";
        return;
    }

    //r02 linker 69
    score = 0;
    cur_score = 0;
    for(int i = 61; i < 76; ++i){
        if(model.substr(i, 1) == read.substr(i, 1))++cur_score;
        if(model.substr(i, 1) == read.substr(i - 1, 1))++score;
    }
    if(score > cur_score){
        read = read.substr(0, 61) + "N" + read.substr(61, read.length()-61);
        quality = quality.substr(0, 61) + "I" + read.substr(61, quality.length()-61);
        cur_score = score;
    }
    if(cur_score < 8){
        read = "Low Quality";
        return;
    }

    //r01 probe 106
    score = 0;
    cur_score = 0;
    for(int i = 99; i < 114; ++i){
        if(model.substr(i, 1) == read.substr(i, 1))++cur_score;
        if(model.substr(i, 1) == read.substr(i - 1, 1))++score;
    }
    if(score > cur_score){
        read = read.substr(0, 99) + "N" + read.substr(99, read.length()-99);
        quality = quality.substr(0, 99) + "I" + read.substr(99, quality.length()-99);
        cur_score = score;
    }
    if(cur_score < 7){
        read = "Low Quality";
        return;
    }

    //barcode quality Q33 (int)'Base' >= 63
    for(int i = 0; i < 8; ++i){
        if((int)(quality[i+0]) < 53 || (int)(quality[i+38]) < 53 || (int)(quality[i+76]) < 53 || (int)(quality[i+114]) < 53)quality="Low Quality";
    }
    return;
}


///// Local functions

int align_score(string str1, string str2){
    /// give the str align score
    /// aligned, +2; misaligned, -2; N contain, 0

    //if(str1.length() != str2.length())return -1;
    int score = 0;
    for(int i = 0; i < str1.length(); ++i){
        if(str2[i] == 'N')continue;
        str2[i] == str1[i] ? (score += 2) : (score -= 1);
    }
    return score;
}

char str2char(string str) {
    stringstream tmp;
    tmp << str;
    char output;
    tmp >> output;
    return(output);
}

string get_read_type(string typ){
    /// classify the read to DNA("d") or RNA("r") read
    /// if cannot distinguish, return "n"
	/// 19;//dna reads:AGATGTGT ATAAGAGACAG, rna reads: N8+T15
	//
    int score = 0;
    if(typ[8] == 'A')++score;
    if(typ[10] == 'A')++score;
    if(typ[11] == 'A')++score;
    if(typ[12] == 'G')++score;
    if(typ[13] == 'A')++score;
    if(typ[14] == 'G')++score;    
    if(typ[15] == 'A')++score;
    if(typ[16] == 'C')++score;
    if(typ[17] == 'A')++score;
    if(typ[18] == 'G')++score;
    if(score > 5){
        return("d");
    }
    int score_rna = 0;
    if(typ[8] == 'T')++score_rna;
    if(typ[10] == 'T')++score_rna;
    if(typ[11] == 'T')++score_rna;
    if(typ[12] == 'T')++score_rna;
    if(typ[13] == 'T')++score_rna;
    if(typ[14] == 'T')++score_rna;
    if(typ[15] == 'T')++score_rna;
    if(typ[16] == 'T')++score_rna;
    if(typ[17] == 'T')++score_rna;
    if(typ[18] == 'T')++score_rna;

    if(score_rna > 5){
        return("r");
    }

    if(score_rna == score) {
        return ("n");
    }
    else if(score > score_rna){
        return ("d");
    }
    else{
        return ("r");
    }
}

//string get_bc_number(string bc, int score){
string get_bc_number(string bc, int score){
//string get_bc_number(string bc, int score, map<string, string> *bc_library){
    string bc_number = "00";
    int cur_score = 0;
    int valid = 0;
    //int score = 0;

    string bc_library[48] = {
"AACGTGAT", "AAACATCG", "ACCACTGT", "CATCAAGT", "CTGTAGCC", "AACCGAGA", "AAGGTACA", "ACAGCAGA", "ACCTCCAA", "ACGCTCGA", "ACTATGCA", "AGAGTCAA", "AGATCGCA", "CAATGGAA", "CAGCGTTA", "CATACCAA", "CCAGTTCA", "CGAACTTA", "CGACTGGA", "CTCAATGA", "CTGAGCCA", "GAATCTGA", "GAGCTGAA", "GATAGACA", "GCTAACGA", "GCTCGGTA", "GGAGAACA", "GGTGCGAA", "GTACGCAA", "GTCGTAGA", "GTGTTCTA", "TCTTCACA", "TGGAACAA", "TGGCTTCA", "TGGTGGTA", "TTCACGCA", "AACTCACC", "AAGAGATC", "AAGGACAC", "AATCCGTC", "ACACGACC", "AGCCATGC", "ATCATTCC", "CACCTTAC", "CCTAATCC", "CCTCTATC", "GAACAGGC", "GATGAATC"
};
        int t = 48;
	if(bc.length() == 5)t = 20;
    	int id = 0;
    	for(int i = 0; i < t; ++i){
        string str_target = bc_library[i];

        cur_score = align_score(bc, str_target);
        if(cur_score < score){
            continue;
        }
        else if(cur_score == score){
            valid = 0; // this is necessary for if two not perfectly matched have same score, it will consideras not matched, even if its score is more than cutoff.
        }
        else{
            valid = 1;
            score = cur_score;
            id = i;
            if((cur_score == 16 && t == 48) || (cur_score == 10 && t == 20)){
                break;
            }
        }
    }

    if(valid == 0)bc_number = "00";
    if(id < 9){
        bc_number = cxstring::int2str(id + 1);
        bc_number = "0" + bc_number;
    }
    else{
        bc_number = cxstring::int2str(id + 1);
    }
    return bc_number;
}
// score was defined mannually, for paired-tag, it used 5 for 7bp BC and 3 for 3bp BC as cutoff,this means 7bp BC has 4 matched (score 8) and 3 mismatched (score -3), 3 bp BC has 2 matched (score 4) and 1 mismatched (score -1); so it consider >= 5 matched (2 mismatched) 7 bp BC and all 3 bases matched 3 bp BC as matched BCs
// for 8bp BC: if 5 bases matched, score==7; if 6 based matched, score==10; set score==7 means at least 6 out of 8 bases matched
// for 5bp BC: if 3 bases matchec, score==4; if 4 based matched, score==7; set score==4 means at least 4 out of 5 bases matched


//string get_bc_number(string bc, int score){
string get_bc_number_4(string bc, int score){
//string get_bc_number(string bc, int score, map<string, string> *bc_library){
    string bc_number = "00";
    int cur_score = 0;
    int valid = 0;
    string bc_library[20] = {
"AATGG", "TGAGA", "CCATA", "GGTGT", "AGCAA", "CCTAA", "GTCGA", "TGTGA", "CTGCA", "TCGAG", "ATAGG", "GAATG", "ACTTG", "ACAAC", "TAGGC", "GATCC", "TCAGT", "AACGT", "TGGCT", "CAGTT"
//"CATC", "ATGA", "AGCT", "ACAG", "GAAT","TACG","TTAC","GTTG","CCGT","CGAA","TCTA","GGGC"

};
    int t = 20;
    int id = 0;
    for(int i = 0; i < t; ++i){
        string str_target = bc_library[i];
        cur_score = align_score(bc, str_target);
        if(cur_score < score){
            continue;
        }
        else if(cur_score == score){
            valid = 0;
        }
        else{
            valid = 1;
            score = cur_score;
            id = i;
            if(cur_score == 10){   //(cur_score == 6 && t == 96) || (cur_score == 6 && t == 12)){
                break;
            }
        }
    }

    if(valid == 0)bc_number = "00";
    if(id < 9){
        bc_number = cxstring::int2str(id + 1);
        bc_number = "0" + bc_number;
    }
    else{
        bc_number = cxstring::int2str(id + 1);
    }
    return bc_number;
}


