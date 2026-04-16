/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_find_payload_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: fcf */
/* WARNING: Unknown calling convention */

uint16_t aps_frame_find_payload_offset(zmsg_t *msg)

{
  byte bVar1;
  uint16_t offset;
  short sVar2;
  byte bStack_12;
  byte abStack_11 [3];
  uint8_t fcf;
  uint8_t ext_fcf;
  
  bStack_12 = 0;
  zmsg_read_u8(msg,0,&bStack_12);
  bVar1 = bStack_12;
  offset = aps_fcf_get_hdr_size(bStack_12);
  if ((char)bVar1 < '\0') {
    abStack_11[0] = 0;
    zmsg_read_u8(msg,offset,abStack_11);
    sVar2 = 1;
    if ((byte)((abStack_11[0] & 3) - 1) < 2) {
      sVar2 = ((bVar1 & 3) == 2) + 2;
    }
    offset = offset + sVar2;
  }
  if ((bVar1 & 0x20) != 0) {
    abStack_11[0] = 0;
    zmsg_read_u8(msg,offset,abStack_11);
    offset = offset + (abStack_11[0] >> 2 & 8) + 5 + (ushort)((abStack_11[0] & 0x18) == 8);
  }
  if ((bStack_12 & 3) == 1) {
    offset = offset + 1;
  }
  return offset;
}

