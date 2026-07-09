/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_iface_mlme_poll_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_iface_mlme_poll_request(int *param_1,char *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if ((*(uint *)(iVar2 + 0x9c) & 1) == 0) {
    return 3;
  }
  uVar1 = 3;
  if (*(char *)(iVar2 + 0x2d) != '\x02') {
    if ((*(char *)(iVar2 + 0x2e) != '\x05') && ((*(ushort *)(iVar2 + 0x30) & 0x20) == 0)) {
      if ((param_2 != (char *)0x0) && (*(short *)(iVar2 + 8) == -1)) {
        if (*param_2 == '\x02') {
          *(undefined2 *)(iVar2 + 0xe) = *(undefined2 *)(param_2 + 2);
        }
        else {
          if (*param_2 != '\x03') {
            return 2;
          }
          memcpy((void *)(iVar2 + 0x10),param_2 + 2,8);
        }
        mac_set_panid(iVar2,*(undefined2 *)(param_2 + 10));
      }
      mac_start_op(iVar2,5);
    }
    uVar1 = 0;
  }
  return uVar1;
}

