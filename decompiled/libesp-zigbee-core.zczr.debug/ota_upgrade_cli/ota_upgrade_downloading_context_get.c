/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_downloading_context_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_downloading_context_get(void)

{
  int iVar1;
  
  iVar1 = ota_upgrade_cli_get_attr_desc(0xeff0);
  if (iVar1 != 0) {
    return *(int *)(iVar1 + 8);
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                        ,0xd7,"ota_upgrade_downloading_context_get","attr_desc");
  **(undefined1 **)(iVar1 + 0x18) = 0;
  **(undefined4 **)(iVar1 + 4) = 0;
  *(undefined1 *)(iVar1 + 0x28) = 0;
  *(undefined1 *)(iVar1 + 0x29) = 0;
  *(undefined1 *)(iVar1 + 0x2a) = 0;
  *(undefined1 *)(iVar1 + 0x2b) = 0;
  *(undefined1 *)(iVar1 + 0x2c) = 0;
  *(undefined1 *)(iVar1 + 0x2d) = 0;
  *(undefined1 *)(iVar1 + 0x2e) = 0;
  *(undefined1 *)(iVar1 + 0x2f) = 0;
  return iVar1;
}

