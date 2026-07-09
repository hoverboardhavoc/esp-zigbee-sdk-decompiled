/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur_ic.o -> secur_ic_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 secur_ic_add(undefined4 *param_1,uint param_2,void *param_3)

{
  uint __n;
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_40;
  undefined4 uStack_3c;
  byte bStack_38;
  undefined1 auStack_37 [19];
  undefined2 uStack_24;
  char cStack_22;
  
  if (param_1 == (undefined4 *)0x0) {
    return 2;
  }
  if ((param_3 != (void *)0x0) && (param_2 < 4)) {
    iVar2 = ic_crc_offset(param_2);
    uVar1 = crc16_next(0xffff,param_3,iVar2);
    if (*(ushort *)((int)param_3 + iVar2) == (ushort)~uVar1) {
      secur_ic_get_stored_ic(param_1,&local_40);
      __n = iVar2 + 2U & 0xff;
      if (cStack_22 == '\0') {
        ds_internal_remove_entry(7,uStack_24,&local_40);
      }
      else if ((bStack_38 == param_2) && (iVar2 = memcmp(auStack_37,param_3,__n), iVar2 == 0)) {
        return 0;
      }
      local_40 = *param_1;
      bStack_38 = (byte)param_2;
      uStack_3c = param_1[1];
      memcpy(auStack_37,param_3,__n);
      uVar3 = ds_internal_add_entry(7,&local_40,0x1b);
      return uVar3;
    }
  }
  return 2;
}

