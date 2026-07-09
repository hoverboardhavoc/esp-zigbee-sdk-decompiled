/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> send_zone_status_change_notif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void send_zone_status_change_notif(undefined1 param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *extraout_a1;
  uint local_30 [2];
  undefined3 uStack_28;
  undefined1 uStack_25;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint3 uStack_18;
  undefined1 uStack_15;
  uint uStack_14;
  
  local_30[0] = 0;
  local_30[1] = 0;
  _uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  _uStack_18 = 0;
  uStack_14 = 0;
  iVar2 = ias_zone_srv_get_attr_desc(0x11);
  if (iVar2 != 0) {
    _uStack_18 = CONCAT13(**(undefined1 **)(iVar2 + 8),(uint3)param_2);
    uStack_14 = uStack_14 & 0xffff0000;
    local_30[0] = local_30[0] & 0xffffff00;
    _uStack_28 = CONCAT13(param_1,uStack_28);
    ias_zone_zone_status_change_notif_cmd_req(local_30);
    return;
  }
  uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x86
                        ,"send_zone_status_change_notif","zone_id_attr_desc");
  iVar2 = ias_zone_srv_get_attr_desc(0);
  if (iVar2 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1e5,
                  "ias_zone_zone_status_change_handler","attr_desc");
  }
  else if (**(char **)(iVar2 + 8) != '\x01') {
    return;
  }
  iVar2 = ias_zone_srv_get_attr_desc(uVar3,2);
  if (iVar2 != 0) {
    uVar1 = **(ushort **)(iVar2 + 8);
    if (((~(uVar1 & 0x3cf) & *extraout_a1 & 0x3cf) != 0) ||
       (((~*extraout_a1 & uVar1) != 0 && ((uVar1 & 0x20) != 0)))) {
      send_zone_status_change_notif(uVar3);
    }
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1e8,
                "ias_zone_zone_status_change_handler","attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

