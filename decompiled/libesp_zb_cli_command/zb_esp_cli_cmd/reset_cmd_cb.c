/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd.o -> reset_cmd_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 reset_cmd_cb(void)

{
  char cVar1;
  undefined4 uVar2;
  char *__s;
  size_t sVar3;
  char *extraout_a1;
  uint uVar4;
  uint uVar5;
  
  uVar2 = esp_log_timestamp();
  esp_log_write(3,0x10000,&_LC1,uVar2,0x10000);
  __s = (char *)esp_restart();
  sVar3 = strlen(__s);
  uVar4 = sVar3 & 0xff;
  if (uVar4 < 3) {
    for (uVar5 = 0; uVar5 < uVar4; uVar5 = uVar5 + 1 & 0xff) {
      if (9 < (byte)(__s[uVar5] - 0x30U)) {
        return 0;
      }
    }
    if (uVar4 == 2) {
      cVar1 = __s[1] + (*__s + -0x30) * '\n';
    }
    else {
      cVar1 = *__s;
    }
    *extraout_a1 = cVar1 + -0x30;
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

