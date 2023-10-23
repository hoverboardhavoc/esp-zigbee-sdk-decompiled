/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> is_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint is_response(char *param_1,int param_2)

{
  uint uVar1;
  
  if (*(char *)(param_2 + 0x10) == '\x03') {
    uVar1 = zb_address_short_by_ieee(param_2 + 8);
  }
  else {
    uVar1 = (uint)*(ushort *)(param_2 + 8);
  }
  if (*(short *)(param_1 + 0xf) == *(short *)(param_2 + 0x14)) {
    if (*(short *)(param_1 + 0x11) == *(short *)(param_2 + 0x12)) {
      if (param_1[0xb] == *(char *)(param_2 + 0x11)) {
        if (*param_1 == '\0') {
          if (*(ushort *)(param_1 + 1) == uVar1) {
            if (((byte)param_1[0x13] - 1 & 0xff) < 0xb) {
              uVar1 = 0x409U >> ((byte)param_1[0x13] - 1 & 0x1f) & 1;
            }
            else {
              uVar1 = 0;
            }
          }
          else {
            uVar1 = 0;
          }
        }
        else {
          uVar1 = 0;
        }
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

