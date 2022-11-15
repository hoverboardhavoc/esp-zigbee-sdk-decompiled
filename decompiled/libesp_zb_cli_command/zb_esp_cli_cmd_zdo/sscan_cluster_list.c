/*
 * Last changed at upstream commit 55d58f0243c7dca5c0887a2b065178dacc2d00be
 * https://github.com/espressif/esp-zigbee-sdk/commit/55d58f0243c7dca5c0887a2b065178dacc2d00be
 * Upstream date: 2022-11-15 14:25:21 +0800
 * Upstream subject: cli: Add cli example
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zdo.o -> sscan_cluster_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool sscan_cluster_list(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  size_t sVar2;
  int iVar3;
  char *__s;
  
  for (uVar1 = 0; uVar1 < (param_2 & 0xffff); uVar1 = uVar1 + 1 & 0xffff) {
    __s = *(char **)(uVar1 * 4 + param_1);
    sVar2 = strlen(__s);
    iVar3 = parse_hex_str(__s,sVar2 & 0xff,param_3,2,1);
    if (iVar3 == 0) break;
    param_3 = param_3 + 2;
  }
  return (param_2 & 0xffff) == uVar1;
}

