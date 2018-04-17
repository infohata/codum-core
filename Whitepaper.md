# Codum
## The Code Marketplace in Blockchain
### V 2.1
### 02.04.2018

### Introduction 

Currently, all cloud based source code repositories and distribution is handled by privately maintained profit oriented companies like Github (by Github Inc., USA), Bitbucket (by Atlassian Pty.Ltd./Inc., Australia), GitLab (by GitLab B.V.,
originated in Ukraine but rebased to USA), Launchpad (by Canonical Ltd., UK), and many others.
Most of them are even proprietary code based, while SourceForge, which is in decline and has already the 3rd owner,
is the only major open source player. This leaves basically all global developer community with having their code repositories serviced by privately owned, profit oriented organizations and closed source infrastructure, while most of them are all based on open source git code repository backend. 
While both Github and Bitbucket offers free to use options for open source code repositories (bitbucket even offers free plan for micro proprietary code developer teams), proprietary code repositories need a constant paid subscription to be online.
Even worse - proprietary code repositories silently are carrying the infrastructure costs of open source code repositories. While this may seem altruistic from such organizations and open source community supposedly should feel grateful, the aspect of centralized control to which community has no voice and that the future is unknown are both apparent.
The question of security and persistence is also valid here. Any repository on, let’s say Github, is alive only until Github is online.If Github fails or goes down forever, the repository with it goes as well. OK, due to distributed development principles of git the code will stay on local machines of developers and ones who cloned it, but further collaborative work on it won’t be possible without a new centrally hosted code repository. How it affects related repositories which use it as dependencies? Catastrophically. Hosting code repository on blockchain is the answer, as the persistence of the repository becomes basically eternal.
Furthermore, the fact of existence of the code in private code repositories is basically void to the World of developers except for its owners, maintainers and developers who work with such code. This leads to constant “reinvention of the wheel” over and over again instead of improving the already existing “wheel”. Currently software development market is undersupplied, and in a such inefficient way that everyone are solving the same problem in competition and wasting time. And this mostly happens just because such private projects and thus private code repositories are not discoverable by any means. Nobody can buy and reuse the unknown.
The solution - blockchain infrastructure based git code repository service with public metadata and secure smart contract licensing. Instead of depending on financially and organizationally vulnerable centralized infrastructure, where centralized owner can make decisions over the community code and dictate terms, the infrastructure is transferred to the DAC - Decentralized Autonomous Community itself. All the code repositories will be encrypted and stored in the blockchain controlled IPFS. Commits entered into repository will remain forever as long as network lives, unlike corporate entity dependent alternatives we have now. By utilizing the DPOS (Delegated Proof of Stake) Blockchain 3.0, infrastructure participants will earn their fair share for delegating their resources to the community infrastructure. 
As in current commercial implementation of existing code repository services, public open source code co-exists with private proprietary code in the same infrastructure. Transactions are processed and their performance depends on delegated stake user has in the blockchain infrastructure. Open source code repositories and their developers will need to be staked to be served, especially when considering a zero resource starting balance. It is possible to allocate minimum viable resources by blockchain consensus to every project or developer in a way that it is enough to start and at the same time it cannot be abused too much to slow down the network. When growing, in such way, open source developers are also motivated to have a part of the network, as they are contributing to the infrastructure they are using themselves, plus they are getting the financial benefit for serving the commercial proprietary codebase, and can have a stake in the grand picture.
By adding the publication capability of the metadata and taxonomy for the private code repositories, codum also provides the so missing visibility feature for the proprietary code - the value of discoverability:

For owners of the code: ability to source and profit from the code by licensing it under smart contracts at any stage of the code lifecycle.

For developers of the code: added value to the work history and profile, and ability to save valuable development time by discovering and outsourcing the existing code from other private repositories in addition to what is available in the open source.

Both sides benefit from wider code reusability and easier integrations naturally happening due to the fact that larger and larger parts of code become common across their projects.
						
All the transactions are formalized in the smart contracts between the parties.
Licensed forks of private repositories may never become open source without the decision of the owner of the parent private repository, while the metadata of such repository would be public without an option. This enables the accounting of chain forking and cloning added to such metadata of all repositories.
Code theft detection is integrated in codum as well: in case cloned/forked repository content appears in the network as a new repository by at least some part, both owners are notified of each other. Such checks are performed by the blockchain infrastructure where finders are rewarded a finder’s premium in case the issue arises from such finding.
Additional values are provided by creating the integrated project management, developer sourcing and market capabilities to the system. Developers gather their portfolio profiles by participating in the projects, both open and proprietary, where such profile data can be used for developer candidate selection process within the system. Employment can then be formalized as a smart contract and payment processed. Also, both contract sides - the developer and the contractor - can rate each other and the rating weight will depend on the smart contract overall value, on top of the success rating gathered from the metadata of the related developments, including such data as estimate overshots, declined pull requests, failed tests and so on.
On top of that all good, software development driven token emerges, together with this newly created development and licensing economy. As software development services are higher in demand than supply, and when developers are taking codum token as preferred way of payment because it comes with the security and profile value for executing the smart contract, codum starts to gain momentum in valuation related to other crypto and fiat currencies, driving all cryptocurrency economy upwards. Companies need software development services and will want to exchange fiat currency into codum to pay developers. Additionally, software licensed through codum will gain demand in mass of the software consumer market with time, becoming the standard in software licensing.

## Platform Overview

### Public Website Frontend

Representative content explaining the codum platform - what it is and how it works
Platform services and user benefits
Price calculator based on real market data
User profile registration and authentication
User Wallet and Smart Contract management
Integrations
InterBC (EOS, Steem, Ethereum, Bitcoin, other altcoins and tokens considered)
Centralized (Google, Github, Facebook, Linkedin, Twitter, etc.)

### Distributed Source Code Repository Management Frontend

Essential functionality for browsing source code repositories like in Github. Including, but not limiting to essential code review and collaboration functionality, served with a different and enhanced User Interface with seamless integration of Project Management with Agile Boards, Task backlog, states, time tracking and insights. In addition to that, it will be fully mobile friendly and operable at all levels - allowing all collaborators to have full control of the situation on the go: from manager being able to redistribute tasks and check on overall progress across the projects, down to developer being able to make a quick fix and see if it builds, and then deploy it. 

### Open Source Code Repositories

All registered and anonymous users are able to see and get everything - source code of all branches, builds, releases, commits, pull requests, related issues in the project management board, and all related entities. Registered users can participate in all development process of public/open source code repositories - fork, code, commit, push and submit a pull request. However, integrated task management helps to easier track progress and assign commits to tasks even after their submission, so it will never be too late to add that comment to commit message.
Owner of the repository is the de-facto moderator/maintainer of the repository as well and is responsible for its content and licensing. However, such roles can be redelegated. Multisignature smart contracts integrate on all levels of codum functionality.
Cloning and forking is not restricted for open source code repositories, however, distribution and derivatives can be enforced by the license if owner/maintainer decides so. Initially it is planned to implement and support GPL 3.0, MIT, BSD, Apache 2.0 license smart contracts.

### Private/proprietary Source Code Repositories 

These work differently than it is implemented now in Github or Bitbucket. The owner of the repository is the user who decides what level of metadata is publically accessible, and what is not. The owner also can delegate responsibility and access to other users or user groups, and roles and access groups logic is shared between code repository and project management functionality. 
Pricing is as flexible and as enabling as it can be thanks to DPOS and Smart Contracts. Private code repository owner is paying not a user headcount (participating staff and developers) or repository number based monthly subscription. The owner is only being charged in real time for network resources utilized related to the source code repository in question.
Public Metadata of the private source code repository - the so missing feature in existing private code repository services. It includes the following data and publication of each position is optional unless Licensing is enforced by Smart Contracts:

Repository name, repository owner/maintainer users and participating users

Public readme file of choice (most text formats supported)

Human readable representation of Licence Smart Contract

Technical git metadata (branches, commit hashes, commit checksums, file checksums).

Licensing of the source code repository becomes available with the above mentioned Public Metadata feature. Once licensing is enabled, for it to work all Public Metadata features must be enabled on the proprietary code project. Due to proprietary nature of such repositories, they cannot be used in open source projects even as dependencies unless the Owner’s repository becomes fully public/open source - the dependency links still can be made but submodule functionality will just not work if user does not possess the License Key to the repository. Licensed repositories will only be able to be accessed via SSH private/public key pair authentication where public key is also a part of the smart contract.

### Initially Planned Smart Contract License Templates

Clone License accounts for “use only” case of license, where Client is entitled to clone the repository for the License fee agreed by the Smart Contract between the Owner and the Client, where Client is granted the Clone Key Certificate. It is SSH security key which entitles the Client read access to the licensed code repository branches and commits. Multiple pricing options are available:

Branch/Commit Limit - each `git clone` action is charged to the Client a full license fee, while `git pull` action is charged to the Client the update fee, but only in case the commit is newer than the one stamped on the license. All current or older `git pull` or `git checkout` actions are not charged. `git fetch` is free of charge all the time.

Periodic User Subscription - each `git clone` action is charged to the Client a full license fee, while `git pull` action is free of charge for the subscription period. If subscription is expired and not renewed, it becomes Branch/Commit Limit Clone License stamped with the latest commits before the expiration timestamp.

Clone Redistribution license enables the Client to include the licensed repository as a dependency to his proprietary source code as git submodule. The Distributor then receives the Redistribution Key Certificate for the repository, which can be used to access the repository by chain. the Owner of the licensed repository receives the benefit of Licensing to his code where perpetual Clone Licenses are issued on demand. 

Fork License enables forking of the repository, where the Client is granted the right to source code derivatives and further redistribution, thus creating the possibility for the Client to participate in the development process. However, Client and Owner must agree on redistribution, intellectual property and other terms. It is possible to set the Client free of obligations as well as restrict it to any physically definable bounding limitations.

Pay per Merge - each merger from upstream is charged the update fee to the client in case there are physical changes in the repository

Periodic Subscription - enables unlimited mergers from upstream for the defined subscription period in the Smart Contact.

Contracted Developer’s Forking - is a special license issued to the contracted developer with the ability to gain read access to the project and ability to fork the repository. However, such license strictly limits the redistribution, including derivatives. Furthermore, the developer with all related contact circles are the first targets of the Knife - so called unlicensed redistribution guard algorithm.

Pull Request Smart Contract enables the Client’s developers to contribute to the Owner’s project and even get paid for it. Issued Pull Request appears on the Owner’s repository (changelog, documentation, changed files and lines and the price). The owner can, from that moment, pull the changes, build and test the submitted code, etc. However, the Owner is not holding any rights to the contributed content before merging the pull request, or fulfilling the smart contract. Knife will work on the benefit of unaccepted/unfulfilled pull request contracts in case such content appears magically in the Owner’s code repository. When the Owner accepts Pull Request, the Client is getting paid for the contribution. If PR submitted content later appears in the Owner’s repository, the Client has a right of compensation and financial obligation of the PR Smart Contract may be executed fully or in parts depending on the situation, and in case defined details in the smart contract are enough to do so, it will be done automatically and immediately.

## Knife - unauthorized distribution and theft protection
“Because it has to be served with the fork”

Blockchain infrastructure providers, motivated by an additional reward opportunity, will be running the bounty hunting Knife operations - theft protection algorithm for code repository owners to enforce licensing terms. Repository owner issues bounty Smart Contract with search criteria and reward for the founder related to owned License Smart Contracts. The bounty criteria can cover selected or all or parts of the Owner’s source code or binary files. The algorithm running on the infrastructure nodes then compares the metadata of the content of the contracted repositories to the metadata content and repository relationships of any other repositories in the network. In case a match is found, both parties (owners of the repositories) are informed of each other. The founder node is rewarded the part of the owner’s contracted bounty once nodes confirm the search is complete against all the network. Reward is result-weighted and distributed to all successful hunters. In case of Licence breach, the repository containing the suspected unlicensed content is suspended from any commercial/licensing operations before the parties resolve the issue, the Owner discards the claim, or no-response timeout happens which is relatively short. The contract is automatically recurring and expires only when Owner decides so, but when there are no more unchecked commits left, the bounty contract is changed from search mode to listen mode. In search mode, the bounty contract is comparing the licensed content to everything is known in the blockchain. In listen mode, everything coming to the blockchain is compared against the licensed content.
System Imposed Knife limitations: for performance reasons, bounty hunting algorithm will prioritize search and will try to find the infringement in logically first possible suspects and repositories according to the metadata existing about the search criteria. First only file metadata (like size, file type/content type, line count, checksums) will be compared. For example, Javascript code will never be compared against C++ code, as it makes no sense. Also files which differ greatly in size and line count will also meet last. Also content which is known as open source content with derivatives allowed and unlimited distribution license terms, will be excluded from the search criteria ignoring any and all false claims to it from both sides, however, timestamps do matter and newly coming content with unlimited licenses will be checked against all there is known. These rules will also enforce private repository owners to properly license such publicly available content even in their repository. 
Legal implications: there will be cases where codum licensing and real world intellectual ownership of non-material property will clash, especially in the early days of codum life. The process of solving such legal issues is well thought through and the solution exists. There are many ways to separate genuinely developed project from archived dump of source code and this will be taken into account. For example, source code repositories forked from other git sources into git, or otherwise having a development history, will have more rightful weight against file dump after git init into a fresh source code repository. There will be also a way to link existing Github, Bitbucket and other 3rd party provider accounts and prove the authenticity. With these mentioned information sources, the owner and the violator can be distinguished without inside the system trustlessly without any human input. In all other cases, where manual decision and legal process will take place, the real source code owner has what to show for it, and is an active maintainer of such code base, sporting the knowledge of most recent issues. The only problem we might have is contract IP infringements of the developers to their customers, and even these partly can be solved by above means, or manually by processing related documentation. In general, such issues would be relevant only at the very beginning where source code would be developed outside the codum development environment, and will be lived out with time.

### Project management frontend

Setting up a project - creating and running the board, task backlog, workflows and development processes, roles and rules for developers, time logs and code delivery performance tracking, issues and reviews - all of that every software project needs and what is Project Manager’s primary responsibility. The ability to execute and run everything close to the source code repository is the key to success for the project owners and managers - as it is running the project all in one place, compared to multitasking across a handful of software. The ability to handle Client and Customer relationships and communication, connecting the issue tracker and backlog, eliminates a lot of misunderstanding and transparency issues and greatly improves project’s performance.

### Ranking, rating and reputation

Developers build their experience and profile with every commit they perform in the system. That includes work on private repositories with published metadata. At the same time, repository owners can showcase their developments at any stage once the metadata of their private code is public.
Rank would be the representation of the weight of total developments performed or owned by the user. Participation is rewarded with rank no matter the outcome.
Rating is the ability for contract sides to rate each other. Developer can rate Employer and Employer can rate Developer at closing of the contract. In addition to such rating, successful contract adds to the reputation and failed contract subtracts from it, balancing the human factor. There is also a pattern driven abuse detection algorithm in place to avoid grief or subjective ranking.
Reputation calculates from the ratio of the rank and weighted average rating, and the price of the weight is determined by the time spent on the task, lines and bytes of code produced, and the price of the contract once Developer Sourcing is implemented. This weighting allows to avoid the situation where a few unsuccessful days of work across freelance contracts may ruin the reputation gained in the years of development. However, if the developer manages to pull out a unicorn project in a ridiculously short period of time, it may be recognized accordingly.

## The Economy

To make the codum token a liquid and feasible utility token it has to become the token driving all the operations performed in the codum service network, be it code repository transactions, project management service infrastructure transactions or sourcing developer work. The token will be placed in exchanges for additional liquidity. As the codum platform use grows with time and it’s demand rises, the valuation for codum token and all related cryptocurrency valuation goes up as well. The infrastructure providing the services of the platform needs codum as a fuel to run on, while the demand for such services forces the acquisition of codum in exchanges from other currencies. Project Owner needs codum to run private software development project, code repository and in the future even to hire developers to execute the development itself, which comes as equity investment into the project. Project Owners issue licenses for the access to the private code repositories to gain codum. Then, Project Owners inline with other blockchain infrastructure providers and developers exchange their gained codum for other equity to balance liquidity in the exchanges globally.

### Competition analysis

GitHub pricing: $9/month per user, starting small teams $25/month includes 5 users. While corporate plans start at $21/user/month requiring additional features and guarantees which would be lived out by the blockchain infrastructure, thus reducing the overall market price.
Bitbucket pricing: free first 5 users, $2/user/month for small teams over 5 users, $5/user/month for large teams requiring additional features and guarantees. This price, however, excludes the project management features of JIRA or Trello, but includes some portion of pipelines and continuous deployment. These are sold as totally separate product with its own pricing, which is a head higher and even more progressive.
Both of the above include the money leaching for long term collaborators and maintainers participating in many projects, as even if they do not contribute any work for a certain amount of time, their presence is charged by the git infrastructure provider. If a developer is participating in 3 large corporate projects on github and takes a month vacation, his presence in the infrastructure costs it’s owners at least $63 for that month alone.

### codum pricing

codum pricing for platform services is micro-transaction based and depends on the activity of the network. Even if the price looks high at first, looking into it long term and at a large scale, savings are huge in comparison to the competitors.
Let’s say we plan the pricing to be equivalent to average spending of $2 per user per month with a sane cap of $8 per month for hyperactive users who are either geniuses or do over hours. Only content publishing agencies may find this quite expensive but that is the point. Casual developer might commit up to 2-3 times on average a day while code prodigy would do up to 10 commits on average a day. Pushing the content to the repository accounts in bytes of pushed content, where transaction fee of content is set to be rounded up to 1kB in precision. Due to the nature of how versioned control system works, every turnover in data change is stored in the system, so all the traffic is assumed to be added to the storage as well. We also assume developers work 20 full-time days a month on average. Text (code) content and binary content is accounted for separately.

Assuming the above, codum service pricing should be capped at these FIAT currency prices on launch:
0.0025€ per push
0.0025€ per 1kB of code/text (non-binary data)
0.00025€ per 1kB of binary data

However, in order to avoid the codum platform to fall out of competitive edge in terms of pricing, the pricing will be auto-regulated in relation to other major currencies. For the time being, it is planned to tie it to the mean rate fluctuations of both infrastructure coin and Euro.

## Fundraising plan

### Token Distribution

codum is issued at 428000000 codum hard cap and will stay at that hard cap forever. The initial network spin-off is sufficient with as little as 1% but the peak network and economic efficiency would start at about 20% of the token supply in constant turnover.

### Private token sale round
Token cap is 19200000 codum. Selling 3840000 codum is enough for success of the private sale round, granting the funding sufficient for the project to go on public sale round. If presale would top out, the project would be guaranteed with enough funding for right away allowing the product development to start in parallel with the ICO preparation.

codum rate offered for the presale period: equivalent of 8 codum for 1 EUR.

Bonus for the first 1.2 million codum: 50% credited when reaching the mark

Bonus for the second 1.2 million codum: 25% credited when reaching the mark

Total private presale token allocation with stimulation bonuses: 5 280 000

### Public token sale round
Capped at 200000000 codum plus the unsold presale tokens and unused presale bonus reserve. 40000000 codum sale is considered public token sale a success granting sufficient funding for the development and launch of the codum platform in full functionality provisioned by this white paper.

codum rate offered for the public sale period: 4 codum for 1 EUR.

Bonus for the first 20 million codum: 20% credited when reaching the mark

Bonus for the second 20 million codum: 10% credited when reaching the mark

Total public sale token allocation with stimulation bonuses: 215000000

The unsold tokens are reserved for the future public fundraising campaigns and will only be available to be used for public fundraising, as the purpose of such tokens is stimulation of codum post product release economy. 

### Reserved codum token distribution

Maximum of 192360000 c_ are reserved for distribution to founder, advisors and contributors to the codum development in case of full private and public token sale out, and a small fraction reserved for company expenses in case the payment can be arranged in codum. In case of just breaking the soft cap on both sales, distributed token amount minimum is 49208372 c_.
The distributed tokens can not be larger than 44.94% of the total tokens in supply. In case codum tokens are burned after all public sales are concluded, the counterpart of reserved tokens will be burned as well.

The reserved tokens will be available for distribution at the rate of 10% per 6 months. The first redistribution will happen right after the first public sale period is closed, before putting the token to the public exchange, and the last 10% will be released 4 years and 6 months after the first distribution event.

Out of all reserved tokens, which amount to 44.94% of the total token supply after the sales has concluded, 25000000 to 100000000 c_ are reserved exclusively for developers involved into the codum development and will be awarded through smart contracts on the merge event of pull requests. 1280000 to 5000000 c_ are used for promotional and social media bounty rewards during the sales. 2550000 to 10000000 c_ are reserved for the company expenses. The rest 19778372 to 77360000 c_ are distributed to project founders and advisors.

### Benefit from the operations of the codum infrastructure
Owners of staked codum tokens will get 10% dividends from the turnover of the token in platform services. This includes, but not limits to: private code repository transactions (push code traffic), repository licensing transactions, Knife success premiums, and all services introduced in the future. 

The dividend payout will occur as soon as the dividend reserve wallet, which would be inaccessible otherwise, reaches 0.1% of the total currently staked codum. 

On the event of dividend payout, the dividend reserve amount is deducted from the dividend reserve account, while all the wallets containing codum stake contracts, gets their stake value multiplied by 1.001 added to their value.

## Technical Background

This section is written with the assumption that reader fully understand the inner workings of both git and EOS.io blockchain.

### Public Metadata
Publishing metadata will be optional for Private/Proprietary code repositories, but will be obligatory for the open source repositories, because not having it would make content of such repositories free for unlicensed grabs. Private code repositories not having public metadata will stay not discoverable as is presently. Portion of Public metadata will be a part of .git directory content in the code repository itself.

## Public Metadata Structure inside the Blockchain
### Repository Meta (name, url, type)
Type is one of: Open Source, Proprietary (with public meta), Private
### Repository Access Data LayER (RADLER)
Information about repository Owner, Administrators, Contributors
Permission and Access Control
Functionality inherited from EOS.io with very minimal modifications
### Branch/Commit tree meta:
Commit Hash
Timestamp
Contributor
### Commercial License Smart Contracts
### Knife Smart Contracts designed to hunt down unlicensed distribution cases
### Meta contents of Branch/Commit/File tree:
File path and name
File size
File type (binary/non-binary)
File content type (text/html/python/cpp/image/pdf/exec/etc.)
File hash generated from the current commit version of that file at the client side of developer’s git. Such hash will allow file comparison without having the file itself, integrity checks and so on.
Current change hash (same as file hash, only applicable to the changes of the current commit)
### Dependencies
Submodule data from git with added Licensing Smart Contracts

## Public Metadata Structure inside Code Repository

### .metadata optional directory, if included, enables public metadata for the repository, with the following content:

Public readme file path or URL in .links file, symlink or README.* file itself

Human readable license file path or URL in .links file, symlink or LICENSE.* file itself

License Smart Contracts

Knife Smart Contracts

Links to 3rd party Continuous Integration and Continuous Deployment solutions to .links

Any 3rd party integrations to .links

.filehash file, storing meta contents of the current branch/commit/file tree. This file is generated for user or 3rd party reference only as a result of the actual commit in git operation, and will never be used as a source for the blockchain data input in the future commits.


Any file in the repository has an option to contain filename.meta.md file, which may contain important data for the developers considering buying and reusing such code - for example, class descriptions, function headers, use cases, and so on. This would solve partially an issue to potentially avoid buying bad code, as code with proper documentation and .meta descriptions on source files would make it more quality. Any other document file formats, even filename.meta.docx, are also supported. Privacy disclaimer: all filename.meta.* files of private repository, but only in case the file filename itself exists, are considered publicly visible, thus the contents of these filename.meta.* files cannot be secret or otherwise commercially sensitive.

### Infrastructure options

Git source code distribution backend running on blockchain infrastructure

Blockchain infrastructure - EOS.io Dawn 3.0

Proxy token for public presale - Ethereum ERC223 or later

IPFS as data storage layer supported by EOS - ipfs.io

### Current relative Open Source resources to look at

One option of principal implementation for decentralized git operations in torrent network is https://github.com/cjb/GitTorrent - it would require the client to install additional package. Another one is to make a gateway over http, both remotely and locally available, where local would of course require to install the gateway app.

Gitchain (https://github.com/gitchain/gitchain) is currently already unfeasible blockchain implementation on Bitcoin. It failed (2k$ real investment only on Kickstarter in 2014). We can salvage the experience with BitCoin.

### Proposed names

Due to Git trademark policy and explanation given by Peff here, we cannot use the git component in the brand name.

Gitereum (domains reserved) is the name of currency itself

Giter is the quantitative unit of the currency

Gitler for source code guard

Codereum in is a good legal alternative for the token

Codeum is shorter version, .io available

## codum even shorter, .io available, CHOSEN

Knife for source code guard

## Team Structure

### C suite (5)
CEO / General Director
CFO / Finance Director
CTO / System Architect
CMO / Marketing & Sales Mastermind with public enterprise launch experience
CCO / Community Manager / PR
### Team Leads (3) on/next to the Cs
Master C++ dev., EOS expert, git/open source master
UI/UX Master
QA Lead
### Community team members (flat, scales with supply)
Development (75%)
C++ Developer (EOS dev., git dev.)
GUI developer / UI/UX master
Frontend Web dev. (AMP/HTML5/CSS3/Angular2)
Backend Web dev. (Python/Django/Storage) in case when unavoidable
With DAWN 3.0 this is possible to avoid very likely
QA / Testing (25%)
### Hired Staff
Deployment and System Administrators
Marketing / Sales
Helpdesk / PR
Accounting

## Schedule and Roadmap

### Whitepaper v1.0
with in-house 3-layer blockchain concept, calculations
2017-09-01 08:00 UTC, done
### Logo Designs, design style
2017-10-01 08:00 UTC, REFACTORING
### Marketing materials
2018-02-09 08:00 UTC, REFACTORING
### Whitepaper v2.x
2018-02-26 16:00 UTC, in-review 2.0
2018-04-02 16:00 UTC, in-review 2.1
### Website Launch
2018-03-19 08:00 UTC REFACTORING, 0.1 LIVE
### Private Fundraising
2018-04-02 12:00 UTC - 2018-08-02 12:00 UTC or when all codum PP tokens sold out
### Public Fundraising and Product Development in parallel
2018-09-10 12:00 UTC - 2019-09-09 12:00 UTC or when all codum PTS tokens sold out

## Extra Features for Future Development

### Continuous Integration and Continuous Deployment
By utilizing blockchain infrastructure to integrate CI and CD into codum platform, we are adding a huge additional value to the platform and its economy. It is even more feasible once EOS.io hits production phase.
### Developer Sourcing
Established infrastructure of source code management and distribution together with project management and internal token driven economy creates the perfect space for one more component in the system - developer work sourcing. And most of the components and infrastructure are already up in place. We have published private project metadata, tasks and code access licensing. And we can implement a chain of smart contracts for executing the developer sourcing with the following logic:

Job offer defines the employment itself by relating to the Project, Task (or tasks) in the backlog, appearing in the job marketplace.
Developers bid their offers to execute the project with their set hiring conditions and estimate. Developer decides how he gets paid, but employer can negotiate it.

Once conditions are subject to agreement, Master Contract is assembled from the Job offer and developer’s bid and becomes binding.
In case code repository is private, during the employment time the developer gets Contracted Developer’s Forking license to the private repository.

Developer, in the process of the developments, submits his Pull Request with contract of acceptance, which also has binding implications to the Employer.

### Physical project management through the system.

Example: event organizing - selling tickets, contracting, sourcing, etc.
