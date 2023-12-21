/*
 * Last changed at upstream commit 790bc8d6ece1bf5f739debaa4aa4af508982070a
 * https://github.com/espressif/esp-zigbee-sdk/commit/790bc8d6ece1bf5f739debaa4aa4af508982070a
 * Upstream date: 2023-12-21 19:52:25 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.7(bdde218a)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> zb_role_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 zb_role_check(char *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    if (3 < uVar1) {
      return 0xff;
    }
    iVar2 = strcmp(param_1,(&PTR__LC93_00012184)[uVar1 * 2]);
    if (iVar2 == 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return (&zb_role_type_str_pair)[uVar1 * 8];
}

