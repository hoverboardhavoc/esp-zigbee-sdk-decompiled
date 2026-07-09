/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_get_comm_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 bdb_get_comm_param(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  
  if (param_1 == 1) {
    if (param_2 == 1) {
      uVar3 = 0xb4;
      goto _L0;
    }
_L0:
    __assert_func(0,0,0,0);
  }
  else {
    if (param_1 == 2) {
      if (param_2 == 4) {
        iVar1 = core_globals_get(2);
        if (*(char *)(iVar1 + 0xd4e) == '\0') {
          uVar2 = nwk_get_pan_channel();
        }
        else {
          iVar1 = core_globals_get();
          if ((*(char *)(iVar1 + 0xd4e) != '\x05') &&
             (iVar1 = core_globals_get(), *(char *)(iVar1 + 0xd4e) != '\x01')) {
            iVar1 = core_globals_get();
            if ((*(byte *)(iVar1 + 0xd5e) & 1) == 0) {
              iVar1 = core_globals_get();
              uVar2 = *(undefined4 *)(iVar1 + 0xd58);
            }
            else {
              iVar1 = core_globals_get();
              uVar2 = *(undefined4 *)(iVar1 + 0xd54);
            }
            *param_3 = uVar2;
            return 0;
          }
          uVar2 = bdb_comm_touchlink_get_channel_mask();
        }
        *param_3 = uVar2;
        return 0;
      }
      goto _L0;
    }
    if (param_1 != 0) {
      log_write(1,"bdb_comm.c",0x10000);
      goto _L0;
    }
    if (param_2 != 1) goto _L0;
  }
  iVar1 = core_globals_get();
  uVar3 = *(undefined1 *)(iVar1 + 0xd50);
_L0:
  *(undefined1 *)param_3 = uVar3;
  return 0;
}

