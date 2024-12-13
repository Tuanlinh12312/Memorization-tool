# Memorization-tool
A tool to help with memorization tests.

## How to use
1. Paste questions into the "questions.txt" file. Insert the number of questions at the beginning of the file. Toggle ShowAns mode by setting it to true/false. Be sure to put each answer in a seperate line after each question. Example in "questionWithAns.txt".
2. Run code. The process will run in rounds. In each round you will be asked questions and should reply with yes(Y), no(N) or unsure(U). More specifically:
- If you are sure that you have the question memorized, respond Y. The question will come back in at most (YSKIP) rounds (default 5). If a question is responded Y (YCNT) times (default 1), it is removed from future rounds.
- If you are unsure about your answer, respond U. The question will come back in at most (USKIP) rounds (default 2).
- If you have no idea, respond N. The question will come back in the next round.
After each response, if ShowAns mode is enabled, the answer to the question will appear.
3. Each round, the questions are shuffled. Rounds will run until all questions have been removed.

## Future features to implement
1. Answers: After answering each question, an answer pops up. (added)
2. Question dependency: You can specify pairs (a, b) - question a must appear before question b each round.
