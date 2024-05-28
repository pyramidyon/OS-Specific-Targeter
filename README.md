# OS Specific Targeter

![image](https://github.com/pyramidyon/OS-Specific-Targeter/assets/88564775/dc9fe80c-fd5c-4beb-966f-6c8d1ca43dcf)

## Overview

The **OS-Specific-Targeter** is a Proof of Concept (PoC) demonstrating the ability to identify the Windows Version using the **Process Environment Block (PEB)** for operating system-specific build vulnerabilities and conditional API calls. This tool is designed to assist in the development of software that can dynamically adapt its functionality based on the version and build of the Windows OS it is executed on.

## Functionality in Malware

Developers of malicious software can for example enhance their programs' resilience against reverse engineering using Native APIs such as NtCallEnclave, NtCreateEnclave, NtInitializeEnclave, NtLoadEnclaveData, and NtTerminateEnclave. While these APIs bolster the effectiveness of attacks, they are only available starting from Windows 10 version 1709. However, malware developers often aim to exploit a broader spectrum of systems, including older ones with potentially lucrative assets like cryptocurrency wallets.

Additionally, this software has applications for targeting specific vulnerabilities present in particular builds of an operating system or software in specific builds.

This Proof of Concept (PoC) demonstrates how attackers could optimally deploy their malware across diverse systems to maximize their return on investment (ROI). 

