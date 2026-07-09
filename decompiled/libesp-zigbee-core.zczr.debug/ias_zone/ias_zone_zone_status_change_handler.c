/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_zone_status_change_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void ias_zone_zone_status_change_handler(undefined4 param_1,ushort *param_2)

{
  ushort uVar1;
  int iVar2;
  
  iVar2 = ias_zone_srv_get_attr_desc(0);
  if (iVar2 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1e5,
                  "ias_zone_zone_status_change_handler","attr_desc");
  }
  else if (**(char **)(iVar2 + 8) != '\x01') {
    return;
  }
  iVar2 = ias_zone_srv_get_attr_desc(param_1,2);
  if (iVar2 != 0) {
    uVar1 = **(ushort **)(iVar2 + 8);
    if (((~(uVar1 & 0x3cf) & *param_2 & 0x3cf) != 0) ||
       (((~*param_2 & uVar1) != 0 && ((uVar1 & 0x20) != 0)))) {
      send_zone_status_change_notif(param_1);
    }
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1e8,
                "ias_zone_zone_status_change_handler","attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

