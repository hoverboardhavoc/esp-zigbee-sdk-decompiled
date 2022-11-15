/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd.o -> parse_hex_str
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool parse_hex_str(char *param_1,uint param_2,byte *param_3,size_t param_4,int param_5)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  byte bVar4;
  int iVar5;
  
  if (((2 < param_2) && (*param_1 == '0')) && (param_1[1] == 'x')) {
    param_2 = param_2 - 2 & 0xff;
    param_1 = param_1 + 2;
  }
  if (param_5 == 0) {
    iVar5 = 1;
  }
  else {
    param_1 = param_1 + (param_2 - 1);
    iVar5 = -1;
  }
  if ((int)(param_4 << 1) < (int)param_2) {
    bVar2 = false;
  }
  else {
    memset(param_3,0,param_4);
    uVar1 = 0;
    while ((uVar1 < param_2 && (uVar3 = parse_hex_digit(*param_1), uVar3 < 0x10))) {
      if ((uVar1 & 1) == 0) {
        if (param_5 == 0) {
          uVar3 = (uVar3 & 0xf) << 4;
        }
        *param_3 = (byte)uVar3;
      }
      else {
        if (param_5 == 0) {
          bVar4 = (byte)uVar3;
        }
        else {
          bVar4 = (byte)((uVar3 << 0x1c) >> 0x18);
        }
        *param_3 = bVar4 | *param_3;
        param_3 = param_3 + 1;
      }
      uVar1 = uVar1 + 1 & 0xff;
      param_1 = param_1 + iVar5;
    }
    bVar2 = param_2 == uVar1;
  }
  return bVar2;
}

