/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_command.o -> zb_zcl_frame_get_sequence_number
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte zb_zcl_frame_get_sequence_number(void)

{
  byte *pbVar1;
  
  pbVar1 = (byte *)zb_buf_begin_func();
  return pbVar1[(-(uint)((*pbVar1 & 4) == 0) & 0xfffffffe) + 3];
}

