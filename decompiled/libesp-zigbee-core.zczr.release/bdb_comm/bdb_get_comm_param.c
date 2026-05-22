/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  uVar4 = *(undefined1 *)(iVar1 + 0xd50);
_L0:
  *(undefined1 *)param = uVar4;
  return 0;
}

