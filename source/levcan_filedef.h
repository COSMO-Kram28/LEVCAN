/*******************************************************************************
 * LEVCAN: Light Electric Vehicle CAN protocol [LC]
 * Copyright (C) 2020 Vasiliy Sukhoparov
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

#pragma once

enum {
	fOpNoOp, fOpOpen, fOpRead, fOpWrite, fOpClose, fOpAck, fOpLseek, fOpData, fOpAckSize, fOpOpenDir, fOpReadDir, fOpTruncate
};

typedef struct {
	uint16_t Operation;
	LC_FileAccess_t Mode;
	char Name[];
} fOpOpen_t;

typedef struct {
	uint16_t Operation;
	uint16_t ToBeRead;
	uint32_t Position;
} fOpRead_t;

typedef struct {
	uint16_t Operation;
	uint32_t Position;
} fOpLseek_t;

typedef struct {
	uint16_t Operation;
} fOpOperation_t;

typedef struct {
	uint16_t Operation;
	uint16_t Error;
	uint32_t Position;
} fOpAck_t;

typedef struct {
	uint16_t Operation;
	uint16_t Error;
	uint32_t Position;
	uint16_t TotalBytes;
	char Data[];
} fOpData_t;

typedef struct {
	char* Buffer;
	uint32_t Position;
	uint16_t ReadBytes;
	uint16_t Error;
} fRead_t;

