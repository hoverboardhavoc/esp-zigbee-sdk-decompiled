/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd.o -> parse_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 parse_address(char *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = strlen(param_1);
  if (param_1 == (char *)0x0) {
    return 0;
  }
  if (param_2 == 0) {
    return 0;
  }
  if (*param_1 == '\0') {
    return 0;
  }
  if ((*param_1 == '0') && (param_1[1] == 'x')) {
    param_1 = param_1 + 2;
    uVar2 = uVar2 - 2;
  }
  if (uVar2 == 0x10) {
    if (param_3 == 1) {
      uVar1 = 3;
      goto _L0;
    }
    if (param_3 == 3) {
      uVar1 = 3;
      goto _L0;
    }
  }
  if (uVar2 != 4) {
    return 0;
  }
  if (1 < param_3 - 1U) {
    return 0;
  }
  uVar1 = 2;
_L0:
  iVar3 = parse_hex_str(param_1,uVar2 & 0xff,param_2,uVar2 >> 1 & 0xff,1);
  if (iVar3 == 0) {
    uVar1 = 0;
  }
  return uVar1;
}

