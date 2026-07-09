/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_handle_upgrade_end
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_handle_upgrade_end(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ota_upgrade_downloading_upgrade_end_is_accepted();
  if (iVar1 == 0) {
    uVar2 = 0xfe;
  }
  else {
    **(undefined4 **)(param_1 + 4) = 0;
    *(undefined1 *)(param_1 + 0x28) = 0;
    *(undefined1 *)(param_1 + 0x29) = 0;
    *(undefined1 *)(param_1 + 0x2a) = 0;
    *(undefined1 *)(param_1 + 0x2b) = 0;
    *(undefined1 *)(param_1 + 0x2c) = 0;
    *(undefined1 *)(param_1 + 0x2d) = 0;
    *(undefined1 *)(param_1 + 0x2e) = 0;
    *(undefined1 *)(param_1 + 0x2f) = 0;
    uVar2 = 0;
  }
  return uVar2;
}

