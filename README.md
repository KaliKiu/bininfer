# bininfer
--**THIS REPOSITORY IS FOR DOCUMENTATION PURPOSES ONLY**-- (WORK IN PROGRESS)

## Planned Features
### Classes:
* Binobj holding file related data + ptr to AnalysisContext obj
* AnalysisContext holding result data
### Stage 1 [Byte Level Statistical & Signature Inference]
* Byte Frequency Historogram        (done) Functions::ByteFrequencyMap(Binobj&)
* Shannon Entropy                   (done) Functions::CalculateShannonentropy(Binobj&)
* Sliding-Window Entropy            (done) Functions::CalculateBlockEntropy(Binobj&)
* Entropy Gradient                  
* Chi-Square Randomness
* ASCII/UTF-8 Likelihood Scoring**
* Magic Number/Header Signature Detection!
* Alignment Detection

->Stage 1 Outputs Region map,Probable Headers etc
