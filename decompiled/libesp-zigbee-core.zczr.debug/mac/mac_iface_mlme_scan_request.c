/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_iface_mlme_scan_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_iface_mlme_scan_request(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *param_2;
  if (bVar1 == 1) {
    uVar2 = mac_active_scan(*param_1,*(undefined4 *)(param_2 + 4),param_2[1],
                            *(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0xc));
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      uVar2 = mac_ed_scan(*(undefined4 *)(param_2 + 4),param_2[1],*(undefined4 *)(param_2 + 8),
                          *(undefined4 *)(param_2 + 0xc));
    }
    else {
      uVar2 = 2;
    }
  }
  else if ((byte)(bVar1 - 2) < 3) {
    uVar2 = 6;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

