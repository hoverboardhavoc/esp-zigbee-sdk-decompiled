/*
 * Last changed at upstream commit d04ab25a7353bae74042267d24c5fef5f02d0726
 * https://github.com/espressif/esp-zigbee-sdk/commit/d04ab25a7353bae74042267d24c5fef5f02d0726
 * Upstream date: 2023-08-08 16:02:31 +0800
 * Upstream subject: esp-zigbee-sdk: add touchlink example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_general_cmd.o -> is_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 is_response(char *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_2 + 2) == '\x03') {
    uVar1 = zb_address_short_by_ieee(param_2 + 3);
  }
  else {
    uVar1 = (uint)*(byte *)(param_2 + 4) << 8 | (uint)(*(ushort *)(param_2 + 2) >> 8);
  }
  if (*(short *)(param_1 + 0xf) == *(short *)(param_2 + 0xe)) {
    if (*(short *)(param_1 + 0x11) == *(short *)(param_2 + 0xc)) {
      if (param_1[0xb] == *(char *)(param_2 + 0xb)) {
        if (*param_1 == '\0') {
          if (*(ushort *)(param_1 + 1) == uVar1) {
            if (param_1[0x13] == '\v') {
              uVar2 = 1;
            }
            else {
              uVar2 = 0;
            }
          }
          else {
            uVar2 = 0;
          }
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

