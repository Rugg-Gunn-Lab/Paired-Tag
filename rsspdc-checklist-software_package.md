# Software Packages

*[Research Software Sharing, Publication, & Distribution Checklist](https://gitlab.com/HDBI/data-management/checklists)*

Considerations for publishing a software package which may be used in research or as a researcher

## 📒Source control

*How can you keep track of the history of your project and collaborate on it?*

- [ ] Uses [git](https://git-scm.com/) (or other source control tool such as [fossil](https://fossil-scm.org/home/doc/trunk/www/index.wiki))
	- [ ]  	🥉Bronze *(Easy)*: Using version control but has a shallow project history, just placed in git for distribution
	- [ ]  	🥈Silver *(Intermediate)*: Longer project history, commit messages of mixed quality, some large messy changes
	- [ ]  	🥇Gold *(Hard)*: Silver plus - Well written commit messages, nice granular commits making discrete self-contained changes.
		   Tags, releases, or branches at major project milestones, maybe some contributions from other users
	- [ ]  	🏆Platinum *(MAXIMUM OVERKILL)*: Gold plus - Some from:
		[conventional commits](https://www.conventionalcommits.org/en/v1.0.0/);
		Clean history with a consistent rebasing/merging strategy;
		Signed commits from all contributors;
		Contributions go through a consistent workflow like, issues, then a pull request from a branch.

<details>
<ul>
	<li>
	If the language you are writing in has a convenient tool for initiating a template for a package then you may want to get your project's git repository started using that tool.
	R for example has the {[usethis](https://usethis.r-lib.org/)} package which makes the creation of a minimal R package very easy, including adding automated building and testing with github actions.
	</li>
</ul>
</details>

## ©Licencing

*On what terms can others use your code, and how can you communicate this?*

- [ ] Project is suitably licensed
	- [ ]  	🥉Bronze *(easy)*: There is a LICENSE file in the repository for a license which meets one of the [OSI](https://opensource.org/osd), [Debian](https://www.debian.org/intro/free), or [FSF/GNU](https://www.gnu.org/philosophy/free-sw.en.html) definitions of free/libre or open source software.
			Or for any contents that are not software a [Creative Commons](https://creativecommons.org/) license.
	- [ ]  	🥈Silver *(easy)*: If any prose/documentation or images is licensed differently from the code in the project this is indicated and those licences provided.
			If licences have an attribution requirement there is are easy to copy text/links for appropriate attribution.
	- [ ]  	🥇Gold *(intermediate)*: Uses [REUSE.software](https://reuse.software/) to provide license information for every file.
	- [ ]  	🏆Platinum *(intermediate)*: all previous tiers plus any images have licensing information embedded in their metadata.

<details>
<ul>
	<li>
	**All software needs a license if you want to permit others to reuse it.**
	It is important to give some thought to the type of license which best suits your project, it is a choice which can have significant long term implications.
	Checkout [the turing way chapter on licensing for an introduction to the subject](https://the-turing-way.netlify.app/reproducible-research/licensing.html).
	If you have no time some pretty safe choices are: For a permissive license, the Apache 2.0.
	This would allow the re-use of your work in closed commercial code.
	For a 'copyleft' license, the GPLv3 (AGPL for server-side apps).
	This requires that anyone distributing software containing your code or derivatives of it share the source code with the people they distributed it too.
	</li>
	<li>
	If you are including external code in your package then you should check that their licenses are compatible and you are legally allowed to distribute your code together in this way.
	Checkout this [resource on license compatibility](https://the-turing-way.netlify.app/reproducible-research/licensing/licensing-compatibility.html).
	</li>
	<li>
	[REUSE.software](https://reuse.software/) is a tool that can help you keep track licenses in complex multi-license projects.
	It identifies licences for code in individual files with [SPDX](https://spdx.dev/) licence codes and has an approach to doing so for binary assets.
	</li>
</ul>
</details>

## 📖Documentation

*How do people know what your project is, how to use it and how to contribute?*

- [ ] Project has suitable documentation 
	- [ ] 	🥉Bronze *(easy)*: Project has README file
		- [ ] README provides a description of the project structure so that the user knows which directories to find things in
	- [ ]  	🥈Silver *(intermediate)*:  If your language has a in-line documentation with which you can build documentation for your functions/objects etc. you are making full use of it.
			So that features such as the ability to produced a reference manual for all the key functional units of your code, and integrations with IDE (integrated development environment) features such as search, templates, and autocomplete can be made the most of.
	- [ ]  	🥇 Gold *(time consuming)*: Your Documentation features examples; rich, varied and working ones.
			Examples should cover both simple and more complex use cases, touching on as much of the functionality as they can.
	- [ ]  	🏆 Platinum *(intermediate)*: All examples are executed upon a full build of the documentation so that you know that they at least run.

In some cases for small and simple projects a README file is sufficient documentation.
This may genuinely be all that you need, or inadequate to the task depending on the project.

<details>
<ul>
	<li>
		README / Manual
		<ul>
			<li>What your project is and what it does</li>
			<li>install instructions</li>
			<li>
				Contribution guidance
				<ul>
					<li>for example: Issue templates, a code of conduct, process details</li>
				</ul>
			</li>
			<li>
				development environment setup
				<ul>
					<li>overview of project organisation and structure</li>
				</ul>
			</li>
		</ul>
	</li>
	<li>
	CHANGELOG it can be a good idea to include a CHANGELOG file in your project documenting things which have changed since the previous release.
	This manuscript on [The impact of package selection and versioning on single-cell RNA-seq analysis](https://doi.org/10.1101/2024.04.04.588111) provides a nice case study for why this can be useful in academic settings especially if decisions have been made to change defaults between versions.
	</li>
	<li>
		'docstrings' and similar
		<ul>
			<li>
				Many programming languages have a way of documenting your code inline which can automate the generation of some parts of the documentation.
				This often takes the form of specifically marked-up comments.
				Examples include python's [dockstrings](https://peps.python.org/pep-0257/), R's [Roxygen2](https://roxygen2.r-lib.org/), and perl's [POD](https://perldoc.perl.org/perlpod)
			</li>
		</ul>
	</li>
	<li>
		Vignettes / Examples
		<ul>
			<li>
				Examples of use of the code in the context of a real problem, beyond simple example snippets which might be included in the documentation of individual functions/objects.
				(These can also serve as a form of simple integration tests if you run them as a part of your documentation build.)
			</li>
		</ul>
	</li>
	<li>Larger projects might also include Project Documentation: Plans, Design documents and Specifications</li>
	<li>
		Process Documentation: how to proceeded with various tasks related to the project this might include: submitting issues, submitting merge requests, reporting possible vulnerabilities, testing, documentation, release, code review review
	</li>
</ul>
</details>

## 🔗Making Citable

*How should people make reference to your project and credit your work?*

- [ ] Package is Citable
	- [ ]  	🥉Bronze *(easy)*: A [CITATION.cff](https://citation-file-format.github.io/) file exists in the code repository to provide citational metadata about your project
	- [ ]  	🥈Silver *(easy)*: bronze plus the project has persistent resolvable identifier such as a DOI or SWHID, with which it can be referenced, which has been minted for the project using a tool like [zenodo](https://zenodo.org/) or [Software Heritage's Archive](https://www.softwareheritage.org/) to store an archival the project.
	- [ ]  	🥇Gold *(intermediate)*: silver plus:
		- [ ] Contributions are credited using a suitable contributor roles ontology or taxonomy (CROT) such as [CrediT](https://credit.niso.org/),[ScoRo](http://www.sparontologies.net/ontologies/scoro),[CRO](https://github.com/data2health/contributor-role-ontology), or [TaDiRAH](https://tadirah.info/).
		- [ ] All contributors are identified by their [ORCID](https://orcid.org/) or other suitable persistent identifier
	- [ ]  	🏆Platinum *(mixed)*: gold plus any two or more from:
		- [ ] (easy) All research institutions are identified by their [ROR](https://ror.org/) ID
		- [ ] (intermediate) Versioned persistent identifier with automation to update snapshots on zenodo or similar tool when a new version is created.
		- [ ] (intermediate) Annotating work cited in this work with the [Citation Typing Ontology (CiTO)](http://purl.org/spar/cito)
		- [ ] (hard) Package your software for Nix or Guix - this might not seem like it contributes to making software more citable see details below for why this is the case.

<details>
It is important that code used in research can be properly cited by researchers so that they can communicate which version they used, where to find the code, and give appropriate credit to it's authors.
Even if you are not an academic it is important that academics be able to credit your work so that it can be appropriately valued in the scientific funding ecosystem.
If it is not framed as contributing to a research output it is harder to justify funding it and paying developer salaries - even if indirectly.

Beyond merely making it possible to consistently reference a research output the higher tiers on the checklist don't merely make the output citable but help to follow better citation and bibliographic practices.
This extends from the practical, making it easy import into reference mangers like [zotero](https://www.zotero.org/);
To protecting against link-rot through the use of persistent digital object identifiers;
To the use of linked / semantic data practices identify and connect contributors, the nature of their contributions, their institutional assoications and thing to which they contributed.

Further information:   
<ul>
	<li>
		Including a [CITATION.cff](https://citation-file-format.github.io/) (Citation File Format) file in your project repo is a simple way of making your code citable. The format is readable in YAML and permits the provision of the metadata needed for citation.
	</li>
	<li>
		[Zenodo](https://zenodo.org/) permits you to mint a [digital object identifier (DOI)](https://www.doi.org/) for your code this is a persistent identifer which can be used to refer to it.
		You can tie the minting versioned DOIs to your releases of your project.
		Using a DOI permits the existing ecosystem of academic software, e.g.[zotero](https://www.zotero.org/), to use APIs to retrieve citational metadata about your project.
		[Zenodo](https://zenodo.org/) also hosts a snapshort of your sourcecode so that if your main code repository ever went down it's still possible to retrieve it here.
		Citational metadata can be import from a [.cff](https://citation-file-format.github.io/) file or a [.zenodo.json](https://developers.zenodo.org/) file in your repository.
		This makes it pretty easy to manage updates as you can just edit these files and have a platform integration or step in your CI push them to zenodo next time you do a release.
	</li>
	<li>
		[Software Heritage](https://www.softwareheritage.org) is an expansive archive of open source software operated by a non-profit organisation in collaboration with UNESCO [how to reference and archive code in software heritage](https://www.softwareheritage.org/howto-archive-and-reference-your-code/).
		SWHIDs have the advantage that they are content based identifiers meaning that you can check if the content you get back when you retrieve it is what you expected to get based on its identifier.
		The Software heritage API permits you to automate the archiving of your project repository via a webhook from popular git forges like github, gitlab and others.
		Unlike Zenodo which only preserves a snapshot of your repository at the time of deposition and at subsequent manual time points and/or tagged releases Software Heritage archives the whole repository.
	</li>
	<li>
		Further reading on the [ethics of CROTs (contributor roles ontology or taxonomy)](https://doi.org/10.1080/08989621.2022.2161049), and their [evolution and adoption](https://doi.org/10.1002/leap.1496).
		This is potentially useful in selecting a CROT suitable for you project
	</li>
	<li>
		Nix and GUIX
		<ul>
			<li>
				General software repositories may not make specific provision for citation of software packages in the academic fashion.
				However some provide, what is for some use cases, a superior form of 'citation' of their own sources i.e. a complete 'software bill of materials (SBOM)'.
				This is a list of all the code used in another piece of code, its dependencies, and their dependencies recursively, along with all of their versions.
				For example [Nix](https://nixos.org/) can do this but [Guix](https://guix.gnu.org/) is perhaps the most comprehensive in its approach.
				It not only provides all information necessary for a complete 'SBOM' but, it can [bootstrap](https://guix.gnu.org/en/manual/en/html_node/Bootstrapping.html) software packages in its repository from source with an extremely minimal fixed set of binaries, an important capability for [creating somewhat trustworthy builds](https://www.cs.cmu.edu/~rdriley/487/papers/Thompson_1984_ReflectionsonTrustingTrust.pdf).
				This creates a compute environment which is not only reproducible but verifiable, meaning the source of all of an environments dependencies can in theory be scrutinised.
				It also adopts an approach to commit signing and authorisation of signers that gives it a [currently uniquely complete supply chain security architecture](https://doi.org/10.22152/programming-journal.org/2023/7/1).
				Packages or 'derivations' are 'pure functions' in the sense that only their inputs effect their outputs and they have no side-effects, package builds are sandboxed to prevent dependencies on any external source not explicitly provided as an input and inputs are hashed to ensure that they cannot differ for the value expected when they were packaged.
				This gives these technologies an unrivaled ability to readily demonstrate the reproducibility and provenance of compute environments specified using them.
			</li>
			<li>
				Whilst not yet full implemented and adopted these technologies also aford some fascinating opertunities for seemless access to archival versions of software in the future.
				Due to the similarities in the content based addressing used by Git, Nix, Guix, IPFS (Interplanetary file System) and software heritage's IDs it may be possible to construct an approach to archiving, distributing and caching sources of packages in a way that would ensure that low demand archived software sources and high demand current packages can be distributed transparently through the same mechanism.
				This would in theory permit the reconstruction of any historically specified compute environment that had been archived with no changes to normal workflow, other than perhaps a longer build time.
				This approach also makes the creation of 'mirrors' of the archive relatively simple and requires no client side changes as an IPFS resource will be resolved irrespective of the node on which it is stored.
				See: [NLnet Software heritage and IPFS](https://nlnet.nl/project/SoftwareHeritage-P2P/), [Tweag - software heritage and Nixpkgs](https://www.tweag.io/blog/2020-06-18-software-heritage/), [John Ericson - Nix x IPFS Gets a New Friend: SWH (SoN2022 - public lecture series)](https://www.youtube.com/watch?v=DjJyPzwEzmU)
			</li>
		</ul>
	</li>
</ul>
</details>

## ✅Testing

*How can you test your project so you can be confident it does what you think it does?*

- [ ] Package is appropriately tested
	- [ ]  	🥉Bronze *(easy)*: You have examples in documentation or vignettes which are run and allow you to see 'manually' if your code's output is correct for key functionality
	- [ ]  	🥈Silver *(easy)*: You are using unit tests and an automated testing framework with tests that cover at least your package's core functionality
	- [ ]  	🥇Gold *(intermediate)*: silver plus: You are monitoring your test coverage to get some insight into any important code paths you might be missing
	- [ ]  	🏆Platinum *(intermediate)*: You follow the Test Driven Development (TDD) model, designing and writing test first then writing code to make them pass

<details>
<ul>
	<li>
	A good test suite allows you to refactor your code without fear of breaking its functionality.
	Good tests are agnostic to the implementation details of action that you are testing, so that you can change how you implemented something without needing to change the tests.
	The use of automated testing frameworks is especially useful for software that is under ongoing development as it allows developers to catch the unintended consequences of a change made in one place on some other part of the code that they did not anticipate.
	</li>
	<li>
	Examples of automated testing frameworks include {[testthat](https://testthat.r-lib.org/)} for R & [unittest](https://realpython.com/python-testing/) for python.
	Tools like [Codecov](https://about.codecov.io/) or [coveralls](https://coveralls.io/) in conjucnction with language specific tools such as [covr](https://covr.r-lib.org/) can help with code coverage monitoring and insights.
	</li>
	<li>
	Unit tests allow you to spell out in detail what you expect the behaviour of your software to be under a particular circumstance and test if it conforms to these expectations.
	Automatically running tests like this can be added to CI/CD pipelines on git forges.
	</li>
	<li>
	Test coverage does not necessarily need to be 100% or even especially high but code coverage tools can allow you to spot gaps in test coverage over important parts of your codebase and ensure that you cover them and give you an indication when you added new and poorly covered code to your codebase that you may want to add tests for.
	</li>
	<li>
	Try to make sure that your test suite runs fast so that you can run it regularly and quickly iterate.
	</li>
	<li>
	Test Driven Development (TDD) is the practice of writing your tests first and then developing the code which conforms to these tests.
	It works well if you have an extremenly well defined idea of what exactly you want your code to do and not do.
	</li>
</ul>
</details>

## 🤖 **Automation**

*What tasks can you automate to increase consistency and reduce manual work?*

- [ ] Suitable automations are in place
	- [ ]  	🥉Bronze *(easy)*:
	- [ ]  	🥈Silver *(easy)*:
	- [ ]  	🥇Gold *(intermediate)*:
	- [ ]  	🏆Platinum *(intermediate)*:

<details>
<ul>
	<li>
		**Linting** is a process of statically analysing the source code to catch errors which can be detected without compiling/running the code such as syntax errors.
		Examples include {[lintr](https://lintr.r-lib.org/)} for R and [Ruff](https://docs.astral.sh/ruff/) for Python.
	</li>
	<li>
		**Automate the use of a standard style / format** Using an automated code formatter ensures that your project has consistent code formattin.
		This can forestall such debates among contributors as: 'spaces vs tabs' for indentation,
		at least it can once you have agreed to bake that descision it your formatter and quash further discussion on the topic.
		Examples include {[styler](https://styler.r-lib.org/)} for R and [Black](https://black.readthedocs.io/en/stable/) for python.
	</li>
	<li>
		Building Documentation
	</li>
	<li>
		**[Git hooks](https://git-scm.com/book/en/v2/Customizing-Git-Git-Hooks)** It can be preferable to automate certain actions based on git events
		<ul>
			<li>
				**pre-commit hooks** can be especially useful for automating things like linting and code formatting on your local system before you can commit any changes to your git history which do not conform to these standards
				Another useful application here is where your documentation is built from source documents in your repository and also under version control, a pre-commit hook can ensure that you cannot commit your documentation sources and their build artefacts in an inconsistent state.
				You can even do this with automated testing so contributors cannot push code that breaks tests locally, that way if tests break in continious integration (CI) it's always likely to be something related to differences in the testing environment or conflicting changes.
			</li>
			<li>
				You can write and manage your own [git hooks](https://git-scm.com/book/en/v2/Customizing-Git-Git-Hooks), there is also the tool [pre-commit](https://pre-commit.com/) written in python and configured in yaml which is a package manager for git commit hooks allowing you to simply install and configure many existing hooks.
			</li>
		</ul>
	</li>
	<li>
		**Continious Integration and Deployment (CI/CD)** is broardly automation of the integration of new changes from contributors to your project and the deployment of those changes to your users on an ongoing basis.
		<ul>
			<li>
			Many modern software forges combine hosting of source control with CI/CD tools.
			[Github](https://github.com/) has '[github actions](https://docs.github.com/en/actions)' and [GitLab](https://about.gitlab.com/) has '[gitlab CI/CD](https://docs.gitlab.com/ee/ci/)', these tools are tide to those specific git hosting services meaning that adopting them can generate significant lock-in to that specific git hosting tool/platform.
			[Codeberg](https://codeberg.org/) provides an instance of [Woodpecker CI](https://woodpecker-ci.org/) and there are other git host-agnostic CI/CD tools such as [Jenkins](https://www.jenkins.io/) available.
			</li>
			<li>
				CI/CD pipelines can also be a good place to run linters and code formatters which either reject merges/pushes which do not conform to these standards or automatically apply them and use bots to commit them.
				This can act as a second line of defense to ensure that contributors have linted their code, applied standard formatting and built documentation.
			</li>
			<li>
				CI is a good place to run automated testing so that CD does not deploy anything detectably broken by your automated test suite.
			</li>
			<li>
				CI/CD is a very convenient way to manage documentation websites for your software which are built based of your packages sources.
				For example the {[pkgdown](https://pkgdown.r-lib.org/)} packge for R is specifically for building documentation sites for R packages and integrates with GitHub actions and GitHub pages to do so.
			</li>
		</ul>
	</li>
</ul>
</details>

## 👥Peer review

- [ ] Package has been appropriately reviewed
	- [ ]  	🥉Bronze *(easy)*: Someone other than you has checked over your package and given you feedback
	- [ ]  	🥈Silver *(intermediate)*: You have published your package in a package repository which performs reviews of submissions such as CRAN, (PyPI's review practices would not be adequate for this purpose).
	- [ ]  	🥇Gold *(intermediate)*: You have published your package via an organisation like [JOSS](https://joss.theoj.org/), [rOpenSci](https://ropensci.org/), or [pyOpenSci](https://www.pyopensci.org/) where the code itself is subject to review by other research software developers.
	- [ ]  	🏆Platinum *(hard)*: Silver, gold and some from:
		- Published a peer reviewed article with a scientific review of the theoretical / statistical / mathematical underpinnings of the tool that you implemented in addition to a technical peer review of the code quality. (These may well be seperate reviews for example by a methods journal and a software repository reflecting their different expertise.)
		- You have had and independent 'red team' attempt to find errors in your project and incorporated any relavant changes as a result.
		- Your project is a part of a bug bounty program.

<details>
<ul>
	<li>
	Entities like The [Journal of Open Source Software (JOSS)](https://joss.theoj.org/), [rOpenSci](https://ropensci.org/), [pyOpenSci](https://www.pyopensci.org/) provide a more 'academic peer review flavoured' form of software review and make it easy to cite software in the academic style.
	</li>
	<li>
	Package repositories like [CRAN](https://cran.r-project.org/) and [Bioconductor](https://contributions.bioconductor.org/index.html) have quite robust processes for review of suitability and quality of packages that are listed in these repositories, this is a form of peer-review though with a more technical focus than academic peer review of research manuscripts.
	By contrast [PyPI](https://packaging.python.org/en/latest/tutorials/packaging-projects/) and [npm](https://docs.npmjs.com/creating-a-package-json-file) have minimal review processes and anyone with an account can upload packages which meet their technical specifications for packaging.
	Different language communities have different standards and practices around their major package repositories.
	</li>
</ul>
</details>

## 📦Distribution

- [ ] Package is distributed in appropriate format(s)
	- [ ]  	🥉Bronze *(easy)*: On a software forge (such as [GitHub](https://github.com/) or [Codeberg](https://codeberg.org/)) in a standard package format so that it can be installed as a development package with the language's standard tooling.
	- [ ]  	🥈Silver *(easy)*: Packaged in a language specific package respository such as [CRAN](https://cran.r-project.org/), [PyPI](https://pypi.org/), [crates.io](https://crates.io/), [CPAN](https://www.cpan.org/) etc.
	- [ ]  	🥇Gold *(intermediate)*: Packaged for additional general package mangement tools with better systems dependency management than language specificic package mangers such as [conda](https://conda.org/), better still functional packaging format such as [Nix](https://nixos.org/) or [Guix](https://guix.gnu.org/)
	- [ ]  	🏆Platinum *(intermediate)*: Available in with additional packagement tools, and from additional repositories
		- Not just available in the package format of but present in the package repositories of: [conda forge](https://conda-forge.org/docs/user/introduction/) or better still [NixPkgs](https://github.com/NixOS/nixpkgs/) or [Guix](https://packages.guix.gnu.org/).
		- If applicable it has a [reproducible binary build](https://reproducible-builds.org/) (ideally for all common architechtures)

<details>
<ul>
	<li>
	Packaging your software so that it can easily be installed by package and environment management tools is important to allow people to use your software.
	Using standard packing format and build tools also often makes it easier to automate testing and documentation building from your source code as well as building binary packages for different, versions, operating systems and architectures.
	</li>
	<li>Package repositories and other packaging formats, conda, spack, Nix.</li>
	<li>If you do not have the resources to maintain your package it may be preferable to leave it out of the main package repos, many may not allow your code to be included there without an active maintainer.</li>
</ul>
</details>

## 💽Environment Management / Portability

- [ ] The compute environment needed to build and install the package is well defined
	- [ ]  	🥉Bronze *(easy)*: Makes use of a packaging format that defines dependencies in the package's own languge, but not neceasrily system dependencies
	- [ ]  	🥈Silver *(easy)*: Packaging information captures all dependencies both build and runtime, either manually or in an automated fashion
	- [ ]  	🥇Gold *(intermediate)*: Detailed version information of all dependencies is also captured, this might also include details of compatible version ranges, to facilitate dependency graph resolution in pacakage managers where only one version of a package can be installed in an environment at the same time.
		- conda / environment.yml
	- [ ]  	🏆Platinum *(intermediate)*:
		- Make use of functional package managers like Nix/Guix whose package derivations make the strongest guarantees about the ability to re-build a package as they describe a pure function called in a sandboxed environment.
		- Cross operating system / architecture builds - does your package build on different operating systems and instruction set architectures (arm, x86, RISC-V etc.)

<details>
<ul>
	<li>
	Use of a robust environment management tool for you language which can exactly reproduce the environment in which any given build of your software was made. In particular any released version of your software would ideally be re-buildable from source in a bit for bit fashion.
	</li>
	<li>
	For a software package that people may want to run in many different environments and which may be run with different versions of the language and other packages it is important to check a broad combination of factors which might crop up in environment that people are likely to be using such as:
	</li>
	<li>
	<ul>
	<li>Different operating systems and versions of these operating systems</li>
		<ul>
		<li>e.g. Linux vs Windows vs MacOS, and Win10 vs Win11</li>
		</ul>
	<li>Different language versions</li>
		<ul>
		<li>e.g. R 3.6.3 and R 4.3.2</li>
		</ul>
	<li>Different computational architectures</li>
		<ul>
		<li>x86_64, arm64, RISCV</li>
		<li>There are practically analogous issues with code to run on AMD vs Intel vs Nvidia accelerators</li>
		</ul>
	<li>Combinations of all of the above</li>
	</ul>
	</li>
	<li>You can cover all of these is all combinations, nor do you need to, just cover the ones most relevant to your software and it's users.</li>
</ul>
</details>

## 🌱 Energy Efficiency

- [ ]
	- [ ]  	🥉Bronze *(easy)*:
	- [ ]  	🥈Silver *(easy)*:
	- [ ]  	🥇Gold *(intermediate)*:
	- [ ]  	🏆Platinum *(intermediate)*:

<details>

Everyone likes fast and efficient code, but especially if your code is going to be re-used by a lots of people in a computationally demanding application it can burn a lot of energy.
This translates to carbon emissions, water use and opportunity costs for whatever else could have been done with that energy and compute time.
If you're making a pipeline produces a lot of intermediate files and outputs consider which of these are needed or good defaults, which could be optional and which could be discarded by default.
Defaults are king and people will mostly keep whatever your tool outputs often essentially indefinietly so you can reduce the energy expended on unnecessary storage by keeping your outputs lean.
Consider what can you do to make your code a little more efficient.

Good documentation and good error handing can reduce the number of times people make mistakes using your code that means they re-run or partially re-run their analysis multiple times before they figure out how to use it right.

<ul>
	<li>
	Don't generate unnecessary outputs that will sit on people's drives unused, clean results of intermediate steps
	</li>
	<li>
	for pipelines in particular caching results and avoiding needing to re-compute things if possible - make best use of these features in pipeline managers for example by having small granular tasks to minimise repeated work on run failure.
	</li>
	<li>
	Choice of libraries and frameworks - some libraries may be more efficient that others or be a wrapper around an efficient implementation in another language, or be able to make use of offload to hardware accelerators.
	</li>
	<li>
	benchmarking & Profiling to locate and improve inefficient code
	</li>
	<li>
	Language Choice
	</li>
	<li>
	Offload to harware accelerators
	</li>
</ul>
</details>

## ⚖ Governance, Conduct, & Continuity

How can you be excellent to each other, make good decisions well, and continue to do so?

- [ ] The project has a suitable governance model
	- [ ]  	🥉Bronze *(easy)*: The governance model is clearly communicated
	- [ ]  	🥈Silver *(easy)*: Bronze Plus - Project has continuity planning in place (2 or more from)
		- [ ] Source archived and/or mirrored to other platforms
		- [ ] Public archives of key project governance documentation and plans for continuity of operations in the events such as the loss of key project infrastructure
		- [ ] Plans of action in the event project admin(s) are no longer available
	- [ ]  	🥇Gold *(intermediate)*: Project has a governance model appropriate to its scale
		- [ ]
		- [ ] Project has clear and transparent processes
	- [ ]  	🏆Platinum *(Hard)*: Project has a track record of good governance and policy
		- [ ]
		- [ ] Learned from any mistakes and implemented policy changes as a result

<details>
<ul>
	<li>
	If you are the Benevolent Dictator For Life (BDFL) of your project and the Code of Conduct (CoC) is "Don't be a Dick" that's fine, for many individual hobby projects this a functional reality.
	Becoming a BDFL tends to be the default unless you take steps to avoid it and cultivate community governance as your project begins to grow - failing to do this and being stuck in charge can become quite the burden in sucessful projects.
	Be waring of adopting policies that you lack resources, time, interest, skill, or inclination to be an active enforcer, mediator and moderator of community norms and disputes, It is helpful to be clear about what you can and cannot commit to doing.
	Only by communicating this might you be able to find community members to help you with setting and enforcing these norms, if or when your community attains a scale where this becomes relevant - community management is its own skill set.
	If you can't moderate them avoid creating and/or continuing ungoverned community spaces that can become a liability for you and your project's reputation.
	Just as there are off-the-shelf licenses there are off-the-shelf codes of conduct, the [Contributor Covenant](https://www.contributor-covenant.org/) is perhaps the best known and most widely used, though may need some customisation to your needs.
	Adopting such a CoC gives you some guidance to follow if there is bad behaviour in your project's community and communicates that you as the project leadership take the responsibility of creating a respectful environment for collaboration seriously.
	It can also signal that your project is a place where everyone is wellcome but expected to treat one another with respect, and that failing to do so will result in penalties potentially including exclusion from the community.
	[The Turing Way](https://doi.org/10.5281/zenodo.3233853) provides quite a nice example of a [CoC developed specifically for their project](https://web.archive.org/web/20240412122958/https://book.the-turing-way.org/)
	You will need to provide contact information for the person(s) responsible for the enforcement of the CoC in the appropriate place and be able to follow up in the event it is used.
	git forges often recognise files with the name `CODE_OF_CONDUCT.md` in the root of project and provide a link to them on project home pages, so this is a good place to document such policies.
	If you are the BDFL of a small project then interpretation and enforcement of such a CoC tends to fall solely on you - game out some courses of action for what you'd do if faced with some common moderation challenges.
		<ul>
			<li>
				Once a project attracts a larger community there is greater scope for disputes and therefore for the need for dispute resolution mechanisms.
				Free/Libre and Open Source Software development and maintenance can be thought of as a commons so I would refer you to the [work of Elinor Ostrom](https://archive.org/details/ElinorOstromGoverningTheCommons) on how commons have been successfully (or unsuccessfully) governed when thinking about what processes to adopt for your project.
				More recently [Nathan Schneider's Governable Spaces: Democratic Design for Online Life](https://doi.org/10.1525/luminos.181) tackles some of these issues as applied to online spaces.
			</li>
			<li>
				This is summarised in the [8 Principles for Managing a Commons](https://web.archive.org/web/20240411163813/https://onthecommons.org/magazine/elinor-ostroms-8-principles-managing-commmons/index.html)
				<ol>
					<li>Define clear group boundaries.</li>
					<li>Match rules governing use of common goods to local needs and conditions.</li>
					<li>Ensure that those affected by the rules can participate in modifying the rules.</li>
					<li>Make sure the rule-making rights of community members are respected by outside authorities.</li>
					<li>Develop a system, carried out by community members, for monitoring members’ behavior.</li>
					<li>Use graduated sanctions for rule violators.</li>
					<li>Provide accessible, low-cost means for dispute resolution.</li>
					<li>Build responsibility for governing the common resource in nested tiers from the lowest level up to the entire interconnected system.</li>
				</ol>
			</li>
			<li>
				An informal [do-ocracy](https://web.archive.org/web/20230201164442/https://communityrule.info/modules/do-ocracy/) in the fiefdom of BDFL is often the default state of projects that have not given much conscious thought to how they want to be governed and are thus often subject to many of the same common failure modes of this model.
				How are decisions made in your project? Do you need the mechanisms of governance used by community and civil society organisations?
				By-laws, a committee and/or working groups, general meetings, votes, minutes? A version of these may be necessary to avoid [The Tyranny of Structurelessness](https://web.archive.org/web/20240406094310/https://www.jofreeman.com/joreen/tyranny.htm)
				How can you map these onto your development infrastructure and make the decisions of your governing bodies enactable and enforceable?
			</li>
		</ul>
	</li>
	<li>
	Continuity planning: What happens to your project if something happens to you?
	The code will likely live on due the distributed nature of git but what about the issue tracker, the website etc.
	Who else has the highest level of privilege on your project or a mechanism to attain it?
	The principle of least privilege dictates that you keep the number of people with this level of access to a minimum but you may then create a single point of failure.
	Password managers like [bitwarden](https://bitwarden.com/) have a feature where designated people can be given access to your vault if they request it and you do not deny it within a certain time-frame.
	This could provide a lower level admin with a mechanism to escalate their privileges if you are unable to do this for them.
	However, this delay might be an issue for continuity of operations if administrator action is needed within the waiting period.
	Game it out, have a plan, write it down, let people know you have a plan.
	</li>
	<li>
	Planning how to 'sunset' your project:
	<ul>
	<li>Let people know that it's not receiving active maintenance and might not be updated to new language and package versions if you are not doing this.</li>
	<li>
	It can be useful to indicate the status of the project in it's README, see: [repostatus.org](https://www.repostatus.org/), where they define eight different project statuses.
	<ul>
		<li>*Concept* – Minimal or no implementation has been done yet, or the repository is only intended to be a limited example, demo, or proof-of-concept.</li>
		<li>*WIP* – Initial development is in progress, but there has not yet been a stable, usable release suitable for the public.</li>
		<li>*Suspended* – Initial development has started, but there has not yet been a stable, usable release; work has been stopped for the time being but the author(s) intend on resuming work.</li>
		<li>*Abandoned* – Initial development has started, but there has not yet been a stable, usable release; the project has been abandoned and the author(s) do not intend on continuing development.</li>
		<li>*Active* – The project has reached a stable, usable state and is being actively developed.</li>
		<li>*Inactive* – The project has reached a stable, usable state but is no longer being actively developed; support/maintenance will be provided as time allows.</li>
		<li>*Unsupported* – The project has reached a stable, usable state but the author(s) have ceased all work on it. A new maintainer may be desired.</li>
		<li>*Moved* - The project has been moved to a new location, and the version at that location should be considered authoritative. This status should be accompanied by a new URL.</li>
	</ul>
	</li>
	<li>You can also convert repositories to an archival mode on common software forges like GitHub to indicate that they are no longer being worked on.</li>
	</ul>
	<li>
	<li>
	Does your project take donations?
	Does it have a trademark?
	Does it need a legal entity to hold these?
	Who is on the paperwork and who has signing authority?
	Who keeps track of expenditures?
	Tools & Organisations like [OpenCollective](https://opencollective.com/) can help with some of these issues.
	</li>
	<li>
	If your project has potential cybersecurity implications what procedures do you have in place for people to disclose vulnerabilities in the project so that they can be patched before they are made public.
	What systems do you have in place to disclose a vulnerability once it has been patched and ensure that users know that they need to update.
	</li>
	<li>Whole project data longevity - what plans do you have in place to backup and archive materials pertaining to your project that are not under source control?</li>
	<li>
	User support
		<ul>
		<li>What support can users expect, or not expect?</li>
		<li>Where can they ask for it?</li>
		<li>Is there somewhere where users can provide support to other members of the user community, such as a forum?</li>
		<li>Can they pay for more support?</li>
		<ul>
	</li>
</ul>

</details>

<p xmlns:cc="http://creativecommons.org/ns#" xmlns:dct="http://purl.org/dc/terms/"><a property="dct:title" rel="cc:attributionURL" href="https://gitlab.com/HDBI/data-management/checklists">Research Software Sharing, Publication, & Distribution Checklists</a> by <a rel="cc:attributionURL dct:creator" property="cc:attributionName" href="https://orcid.org/0000-0002-2574-9611">Richard J. Acton</a> is licensed under <a href="http://creativecommons.org/licenses/by/4.0/?ref=chooser-v1" target="_blank" rel="license noopener noreferrer" style="display:inline-block;">CC BY 4.0<img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/cc.svg?ref=chooser-v1"><img style="height:22px!important;margin-left:3px;vertical-align:text-bottom;" src="https://mirrors.creativecommons.org/presskit/icons/by.svg?ref=chooser-v1"></a></p>
