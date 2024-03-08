/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_attr.o -> is_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 is_response(char *param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*(char *)(param_2 + 0x10) == '\x03') {
    uVar2 = zb_address_short_by_ieee(param_2 + 8);
  }
  else {
    uVar2 = (uint)*(ushort *)(param_2 + 8);
  }
  if (*(short *)(param_1 + 0xf) == *(short *)(param_2 + 0x14)) {
    if (*(short *)(param_1 + 0x11) == *(short *)(param_2 + 0x12)) {
      if (param_1[0xb] == *(char *)(param_2 + 0x11)) {
        if (*param_1 == '\0') {
          if (*(ushort *)(param_1 + 1) == uVar2) {
            cVar1 = param_1[0x13];
            if (cVar1 == '\v') {
              uVar3 = 1;
            }
            else if (cVar1 == '\x01') {
              uVar3 = 1;
            }
            else if (cVar1 == '\x04') {
              uVar3 = 1;
            }
            else {
              uVar3 = 0;
            }
          }
          else {
            uVar3 = 0;
          }
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

