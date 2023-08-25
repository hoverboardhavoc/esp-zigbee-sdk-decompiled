/*
 * Last changed at upstream commit 62f83e9155a8a668183e90087b29cd6791297d4c
 * https://github.com/espressif/esp-zigbee-sdk/commit/62f83e9155a8a668183e90087b29cd6791297d4c
 * Upstream date: 2023-08-25 15:56:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.1(b4845e06)
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
    iVar2 = strcmp(param_1,(&PTR__LC95_00012178)[uVar1 * 2]);
    if (iVar2 == 0) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  return (&zb_role_type_str_pair)[uVar1 * 8];
}

