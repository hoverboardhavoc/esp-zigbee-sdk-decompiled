/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd.o -> parse_str_digit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 parse_str_digit(char *param_1,char *param_2)

{
  char cVar1;
  size_t sVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  sVar2 = strlen(param_1);
  uVar4 = sVar2 & 0xff;
  if (uVar4 < 3) {
    for (uVar5 = 0; uVar5 < uVar4; uVar5 = uVar5 + 1 & 0xff) {
      if (9 < (byte)(param_1[uVar5] - 0x30U)) {
        return 0;
      }
    }
    if (uVar4 == 2) {
      cVar1 = param_1[1] + (*param_1 + -0x30) * '\n';
    }
    else {
      cVar1 = *param_1;
    }
    *param_2 = cVar1 + -0x30;
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

