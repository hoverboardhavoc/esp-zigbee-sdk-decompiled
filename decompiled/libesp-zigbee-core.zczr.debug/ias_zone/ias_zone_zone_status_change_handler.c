/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_zone_status_change_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void ias_zone_zone_status_change_handler(uint8_t ep_id,void *new_value)

{
  ushort uVar1;
  uint16_t zone_status;
  zcl_attr_desc_t *pzVar2;
  
  pzVar2 = ias_zone_srv_get_attr_desc(ep_id,0);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1e5,
                  "ias_zone_zone_status_change_handler","attr_desc");
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*pzVar2->data_p != '\x01') {
      return;
    }
  }
  pzVar2 = ias_zone_srv_get_attr_desc(ep_id,2);
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    uVar1 = *pzVar2->data_p;
                    /* WARNING: Load size is inaccurate */
    zone_status = *new_value;
    if (((~(uVar1 & 0x3cf) & zone_status & 0x3cf) != 0) ||
       (((~zone_status & uVar1) != 0 && ((uVar1 & 0x20) != 0)))) {
      send_zone_status_change_notif(ep_id,zone_status);
    }
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1e8,
                "ias_zone_zone_status_change_handler","attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

