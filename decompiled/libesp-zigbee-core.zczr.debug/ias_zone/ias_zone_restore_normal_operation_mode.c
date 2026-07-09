/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_restore_normal_operation_mode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_zone_restore_normal_operation_mode(uint param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int iVar4;
  short *psVar5;
  char *pcVar6;
  short sVar7;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0xb3,
                  "ias_zone_restore_normal_operation_mode",&_L0);
  }
  else {
    puVar3 = (undefined1 *)ias_zone_srv_get_zone_ctx(param_1 & 0xff);
    uVar1 = uStack_14;
    uStack_18 = CONCAT22(0x500,(ushort)(byte)param_1 << 8);
    uStack_14 = CONCAT31(uStack_14._1_3_,1);
    uVar2 = uStack_14;
    uStack_14._3_1_ = SUB41(uVar1,3);
    uStack_14._0_3_ = CONCAT12(0xfe,(short)uVar2);
    zcl_core_action_schedule(0x30,&uStack_18);
    iVar4 = ias_zone_srv_get_attr_desc(param_1 & 0xff,0x13);
    if (iVar4 != 0) {
      if (puVar3[1] != '\0') {
        **(undefined1 **)(iVar4 + 8) = *puVar3;
        puVar3[1] = 0;
      }
      return;
    }
  }
  pcVar6 = "ias_zone_restore_normal_operation_mode";
  psVar5 = (short *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c"
                                  ,0xbf,"ias_zone_restore_normal_operation_mode","attr_desc");
  iVar4 = zmsg_read_bytes(*psVar5,1,pcVar6);
  if (iVar4 == 0) {
    sVar7 = -1;
  }
  else {
    sVar7 = *psVar5 + (short)iVar4;
  }
  *psVar5 = sVar7;
  return;
}

