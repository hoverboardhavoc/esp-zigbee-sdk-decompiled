/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_command.o -> zb_zcl_construct_general_command_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte * zb_zcl_construct_general_command_header
                 (uint param_1,uint param_2,undefined4 param_3,uint param_4,byte param_5)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  pbVar2 = (byte *)zb_buf_reuse_func();
  *pbVar2 = (byte)((param_2 & 0x3f) << 2) | (byte)((param_1 & 0x1f) << 3) |
            (byte)((param_4 & 0xf) << 4);
  pbVar2 = pbVar2 + 1;
  if (param_2 != 0) {
    pbVar2 = (byte *)zb_put_next_htole16(pbVar2,param_3);
  }
  pbVar3 = (byte *)zb_zcl_get_ctx();
  bVar1 = *pbVar3;
  *pbVar3 = bVar1 + 1;
  *pbVar2 = bVar1;
  pbVar2[1] = param_5;
  return pbVar2 + 2;
}

