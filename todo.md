# Transformer in C – Chronological TODO List

## Phase 1: Core Infrastructure

- [ ] Create `tensor.c` and `tensor.h` files
- [ ] Define `Tensor` struct (support dynamic shape, 1D–3D)
- [ ] Implement tensor memory allocation and deallocation
- [ ] Implement matrix multiplication
- [ ] Implement element-wise operations (add, subtract, multiply)
- [ ] Implement transpose operation
- [ ] Implement softmax function
- [ ] Implement tensor shape utilities (print, reshape)
- [ ] Implement tensor random initialization (e.g. Xavier)

## Phase 2: Tokenization & Data Prep

- [ ] Write tokenizer to split sentences into words
- [ ] Build vocabulary from training sentences (word → index)
- [ ] Convert sentences to sequences of token IDs
- [ ] Create input-target pairs for training (next word prediction)

## Phase 3: Model Components

- [ ] Implement embedding layer (lookup table)
- [ ] Implement positional encoding (sine/cosine or learned)
- [ ] Implement scaled dot-product attention
- [ ] Implement multi-head attention
- [ ] Implement feedforward network (2 linear layers + activation)
- [ ] Implement layer normalization
- [ ] Implement residual connections

## Phase 4: Model Assembly

- [ ] Implement a single transformer encoder block
- [ ] Stack multiple encoder blocks (e.g. 2–6)
- [ ] Add final linear layer to project to vocabulary size
- [ ] Add softmax layer for output probabilities

## Phase 5: Training

- [ ] Implement cross-entropy loss function
- [ ] Implement forward pass through model
- [ ] (Optional) Implement backpropagation manually or use numerical gradients
- [ ] Implement simple SGD or Adam optimizer
- [ ] Train model on small dataset of sentences
- [ ] Track training loss and accuracy

## Phase 6: Inference

- [ ] Implement text generation function (next word prediction loop)
- [ ] Allow seed text input and generate N words
- [ ] Print or save output sequence

## Phase 7: Utilities & CLI

- [ ] Add command-line interface (train / generate modes)
- [ ] Implement model saving (to file)
- [ ] Implement model loading (from file)

## Phase 8: Documentation & Learning

- [ ] Comment and document all code
- [ ] Write README with usage instructions
- [ ] Take notes on transformer theory, optimization, and LLM architecture
- [ ] (Optional) Draw diagrams of architecture and training flow

## Optional Stretch Goals

- [ ] Implement full transformer decoder block (for seq2seq tasks)
- [ ] Implement BPE or WordPiece tokenizer
- [ ] Add batching and padding support
- [ ] Train on larger dataset (text file or corpus)
- [ ] Benchmark and profile performance
