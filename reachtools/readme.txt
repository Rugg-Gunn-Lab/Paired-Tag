To build and install locally:

``` 
# Clone the base repo
git clone https://github.com/HDBI/Paired-Tag
# Move to the reachtools directory
cd reachtools
# you will need conda build installed if you don't already:
# conda install -n <your env e.g. base> conda-build
conda-build ./
# The output from the build will include the path to where the locally built package is stored
# install the locally built package:
conda install --offline --verbose /path/to/build/result # get from above
```

====================================================================================================

As the library structure of Paired-tag and current version of Paired-seq is different from initial version of Paired-seq described in Zhu et.al., NSMB, 2019, please be aware to use the right version of reachtools.

This one is for Paired-tag/Paired-seq version 2020 only!
For analysis of Paired-seq version 2019 data, please use https://github.com/cxzhu/Paired-seq.
