/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bdb_comm.o -> bdb_get_comm_param
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t bdb_get_comm_param(uint8_t id,uint8_t len,void *param)

{
  undefined3 in_register_00002029;
  int iVar1;
  undefined4 uVar2;
  undefined3 in_register_0000202d;
  int iVar3;
  undefined1 uVar4;
  
  iVar3 = CONCAT31(in_register_0000202d,len);
  iVar1 = CONCAT31(in_register_00002029,id);
  if (iVar1 == 1) {
    if (iVar3 == 1) {
      uVar4 = 0xb4;
      goto _L0;
    }
_L0:
    __assert_func(0,0,0,0);
  }
  else {
    if (iVar1 == 2) {
      if (iVar3 == 4) {
        iVar1 = core_globals_get(2);
        if (*(char *)(iVar1 + 0xda2) == '\0') {
          uVar2 = nwk_get_pan_channel();
        }
        else {
          iVar1 = core_globals_get();
          if ((*(char *)(iVar1 + 0xda2) != '\x05') &&
             (iVar1 = core_globals_get(), *(char *)(iVar1 + 0xda2) != '\x01')) {
            iVar1 = core_globals_get();
            if ((*(byte *)(iVar1 + 0xdb2) & 1) == 0) {
              iVar1 = core_globals_get();
              uVar2 = *(undefined4 *)(iVar1 + 0xdac);
            }
            else {
              iVar1 = core_globals_get();
              uVar2 = *(undefined4 *)(iVar1 + 0xda8);
            }
            *(undefined4 *)param = uVar2;
            return 0;
          }
          uVar2 = bdb_comm_touchlink_get_channel_mask();
        }
        *(undefined4 *)param = uVar2;
        return 0;
      }
      goto _L0;
    }
    if (iVar1 != 0) {
      log_write(1,"bdb_comm.c",0x10000);
      goto _L0;
    }
    if (iVar3 != 1) goto _L0;
  }
  iVar1 = core_globals_get();
  uVar4 = *(undefined1 *)(iVar1 + 0xda4);
_L0:
  *(undefined1 *)param = uVar4;
  return 0;
}

