/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_api.o -> aps_apsde_user_data_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_apsde_user_data_indication(undefined2 *param_1,code *param_2)

{
  undefined4 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int unaff_s1;
  int iVar6;
  int unaff_s2;
  int unaff_s3;
  undefined2 uStack_48;
  undefined2 uStack_46;
  uint uStack_44;
  undefined3 uStack_40;
  undefined1 uStack_3d;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined4 uStack_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  int iStack_24;
  
  if (param_1 == (undefined2 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/aps_api.c",0x35,
                  "aps_apsde_user_data_indication",0x10000);
_L0:
    if (unaff_s1 == 0) goto _L0;
    log_write(2,"aps_api.c","NO MEM for ASDU in APSDE-DATA.indication");
    unaff_s1 = 0;
_L0:
    uVar5 = (undefined2)unaff_s1;
    uStack_3d = 0;
    uStack_3a = 0;
    uVar2 = uStack_3a;
    uStack_3a = 0;
    uStack_38 = 0;
    uStack_2e = 0;
    uVar3 = uStack_2e;
    uStack_2e = 0;
    uStack_2c = 0;
    uStack_26 = 0;
    uVar4 = uStack_26;
    uStack_26 = 0;
    param_2 = s_apsde_data_ind_handler;
    if (param_1[2] != 0) {
      uStack_3d = 0;
      _uStack_48 = CONCAT22(param_1[2],1);
      uStack_44 = (uint)(ushort)param_1[1];
      goto _L0;
    }
  }
  else {
    unaff_s3 = *(int *)(param_1 + 8);
    if (s_apsde_data_ind_handler == (code *)0x0) {
      return 0;
    }
    param_2 = s_apsde_data_ind_handler;
    unaff_s1 = zmsg_get_length(unaff_s3);
    unaff_s2 = mm_alloc_notrap(1,unaff_s1);
    if (unaff_s2 == 0) goto _L0;
_L0:
    iVar6 = zmsg_read_bytes(unaff_s3,0,unaff_s1,unaff_s2);
    if (iVar6 == unaff_s1) goto _L0;
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/aps_api.c",0x43,
                  "aps_apsde_user_data_indication",
                  "asdu_length == zmsg_read_bytes(msg, 0, asdu_length, asdu)");
    uVar2 = uStack_3a;
    uVar3 = uStack_2e;
    uVar4 = uStack_26;
  }
  uStack_26 = uVar4;
  uStack_2e = uVar3;
  uStack_3a = uVar2;
  uVar5 = (undefined2)unaff_s1;
  uStack_44 = 0;
  _uStack_48 = CONCAT22(param_1[1],2);
_L0:
  uVar1 = uStack_2c;
  _uStack_40 = CONCAT13(uStack_3d,0x20000);
  _uStack_3c = CONCAT22(uStack_3a,*param_1);
  _uStack_34 = CONCAT22(param_1[4],
                        CONCAT11(*(undefined1 *)(param_1 + 3),*(undefined1 *)((int)param_1 + 7)));
  _uStack_30 = CONCAT22(uStack_2e,param_1[5]);
  uStack_2c._3_1_ = SUB41(uVar1,3);
  uStack_2c._0_3_ =
       CONCAT12(*(undefined1 *)((int)param_1 + 0xd),
                CONCAT11(*(undefined1 *)(param_1 + 6),(undefined1)uStack_2c));
  _uStack_28 = CONCAT22(uStack_26,uVar5);
  iStack_24 = unaff_s2;
  iVar6 = (*param_2)(&uStack_48);
  if (unaff_s2 != 0) {
    mm_free(unaff_s2);
  }
  if ((iVar6 != 0) && (unaff_s3 != 0)) {
    zmsg_free(unaff_s3);
  }
  return iVar6;
}

