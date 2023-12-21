/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_command.o -> zb_zcl_frame_get_sequence_number
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte zb_zcl_frame_get_sequence_number(void)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = (byte *)zb_buf_begin_func();
  if ((*pbVar1 >> 2 & 1) == 0) {
    iVar2 = 1;
  }
  else {
    iVar2 = 3;
  }
  return pbVar1[iVar2];
}

