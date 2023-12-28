BTCturquoise Core Latest v2.0.54.218
===========================

|CI|master|develop|
|-|-|-|

BTCturquoise Blockchain
Welcome to BTCturquoise, a revolutionary blockchain network offering a compelling alternative to traditional cryptocurrencies. Built upon the foundation of Bitcoin but with notable enhancements, BTCturquoise is a peer-to-peer digital currency designed for efficiency, decentralization, and inclusivity.

CPU-Friendly Mining Algorithm: GhostRider
Unlike Bitcoin's reliance on ASIC-dominated mining, BTCturquoise employs the GhostRider algorithm. This innovative approach encourages CPU mining, enabling broader participation without the need for specialized hardware. It fosters a more inclusive mining environment, promoting fairness and accessibility.

Security, Speed, and Sustainability
With a focus on robust security measures and faster transaction confirmations, BTCturquoise facilitates seamless, near-instant payments globally. Its sustainable supply control and demand-driven approach align with market dynamics, fostering a balanced and reliable ecosystem.

Open Source and Collaborative Development
BTCturquoise operates under the MIT license, encouraging transparency and collaboration within its development community. Active development occurs in separate branches, with stable releases tagged for clarity in the Tags section.

Advantages over Traditional Bitcoin (BTC)
CPU vs. ASIC Mining
BTCturquoise’s GhostRider algorithm promotes CPU-based mining, in stark contrast to Bitcoin's ASIC-centric mining landscape. This approach democratizes mining participation, allowing individuals to contribute to network security without investing in specialized, often costly hardware. The result? A more decentralized, resilient, and community-driven network.

Accessibility and Inclusivity
By prioritizing CPU mining, BTCturquoise aims to level the playing field, welcoming a broader spectrum of participants into the world of cryptocurrency mining. This inclusivity aligns with the original ethos of decentralized currencies, empowering individuals globally to engage in the network's operations.

Sustainability and Innovation
BTCturquoise's emphasis on CPU mining not only enhances network decentralization but also promotes a more sustainable approach to cryptocurrency mining. The reduced energy consumption associated with CPU mining fosters a greener and more environmentally friendly mining process.

----------------------------------------------------------------------------------------------
Coin Properties:

Source branch: v2.0.54.3
Algorithm: Ghostrider
Coin name: BTCturquoise
Coin abbreviation: BTCQ
RPC port: 3333
P2P port: 4444
Block reward 5100 coins
Coin supply: 21,000,000,000 coins
Block Time: 150 SECONDS
Smartnode: 56% SMARTNODE
           29% MINER
           15% DEVELOPMENT
Website URL
https://
Testing
------------------------------------------------------------------------------------------------

Get Involved
Contributions to BTCturquoise are welcomed and encouraged! Refer to CONTRIBUTING.md for guidelines on how to contribute to the project.

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and OS X, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
