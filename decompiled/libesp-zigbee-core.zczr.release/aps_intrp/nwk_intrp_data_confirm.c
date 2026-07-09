/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_intrp.o -> nwk_intrp_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_intrp_data_confirm(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  byte bStack_41;
  undefined1 auStack_40 [4];
  undefined1 auStack_3c [10];
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined1 auStack_28 [10];
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  int iStack_14;
  
  bStack_41 = 0;
  zmsg_read_bytes(*param_1,0,1,&bStack_41);
  if ((bStack_41 & 3) == 3) {
    uVar2 = 7;
    if ((bStack_41 & 0xc) != 0xc) {
      uVar2 = 5;
    }
    zmsg_remove_header(uVar2);
    iStack_14 = *param_1;
    cVar1 = '\0';
    if ((char)param_1[1] != '\0') {
      cVar1 = (char)param_1[1];
    }
    memset(auStack_40,0,0x18);
    zmsg_get_footer(iStack_14,auStack_40,0x18);
    zmsg_remove_footer(iStack_14,0x18);
    uStack_1e = 0;
    uStack_1c = 0;
    uStack_1a = 0;
    uStack_18 = 0;
    uStack_16 = 0;
    memcpy(auStack_28,auStack_3c,10);
    uStack_18 = CONCAT11(uStack_18._1_1_,cVar1);
    uStack_1c = uStack_30;
    uStack_1a = uStack_32;
    aps_intrp_data_confirm(auStack_28);
  }
  else if (*param_1 != 0) {
    zmsg_free();
  }
  return;
}

