/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> secur_ic.o -> secur_ic_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 secur_ic_add(undefined4 *param_1,uint param_2,void *param_3)

{
  int iVar1;
  size_t sVar2;
  undefined4 uVar3;
  undefined4 local_40;
  undefined4 uStack_3c;
  byte bStack_38;
  undefined1 auStack_37 [21];
  char cStack_22;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar3 = 2;
  }
  else if (param_3 == (void *)0x0) {
    uVar3 = 2;
  }
  else if (param_2 < 4) {
    iVar1 = ic_is_valid(param_2,param_3);
    if (iVar1 == 0) {
      uVar3 = 2;
    }
    else {
      secur_ic_get_stored_ic(param_1,&local_40);
      if ((cStack_22 != '\0') && (bStack_38 == param_2)) {
        sVar2 = ic_size(param_2);
        iVar1 = memcmp(auStack_37,param_3,sVar2);
        if (iVar1 == 0) {
          return 0;
        }
      }
      ds_ic_info_delete(&local_40);
      bStack_38 = (byte)param_2;
      local_40 = *param_1;
      uStack_3c = param_1[1];
      sVar2 = ic_size(param_2);
      memcpy(auStack_37,param_3,sVar2);
      uVar3 = ds_internal_add_entry(7,&local_40,0x1b);
    }
  }
  else {
    uVar3 = 2;
  }
  return uVar3;
}

