/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> send_zone_status_change_notif
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void send_zone_status_change_notif(uint8_t ep_id,uint16_t zone_status)

{
  ushort uVar1;
  uint16_t zone_status_00;
  uint8_t ep_id_00;
  zcl_attr_desc_t *pzVar2;
  uint16_t *puVar3;
  undefined1 local_30 [4];
  ias_zone_status_change_notif_cmd_t cmd;
  
  local_30 = (undefined1  [4])0x0;
  cmd.cmd_ctrl.dst_addr._0_4_ = 0;
  cmd.cmd_ctrl.dst_addr.u._2_4_ = 0;
  cmd.cmd_ctrl._8_4_ = 0;
  cmd.cmd_ctrl.dis_default_rsp = false;
  cmd.cmd_ctrl._13_3_ = 0;
  cmd.cmd_ctrl.cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  cmd.cmd_ctrl.cnf_ctx.user_ctx = (void *)0x0;
  cmd.payload.zone_status = 0;
  cmd.payload.extend_status = '\0';
  cmd.payload.zone_id = '\0';
  pzVar2 = ias_zone_srv_get_attr_desc(ep_id,0x11);
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    cmd.cmd_ctrl.cnf_ctx.user_ctx = (void *)CONCAT13(*pzVar2->data_p,CONCAT12(0,zone_status));
    cmd.payload._0_4_ = cmd.payload._0_4_ & 0xffff0000;
    local_30 = (undefined1  [4])((uint)local_30 & 0xffffff00);
    cmd.cmd_ctrl.dst_addr.u._5_1_ = ep_id;
    ias_zone_zone_status_change_notif_cmd_req((ias_zone_status_change_notif_cmd_t *)local_30);
    return;
  }
  puVar3 = (uint16_t *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",
                         0x86,"send_zone_status_change_notif","zone_id_attr_desc");
  pzVar2 = ias_zone_srv_get_attr_desc(ep_id_00,0);
  if (pzVar2 == (zcl_attr_desc_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1e5,
                  "ias_zone_zone_status_change_handler","attr_desc");
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*pzVar2->data_p != '\x01') {
      return;
    }
  }
  pzVar2 = ias_zone_srv_get_attr_desc(ep_id_00,2);
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    uVar1 = *pzVar2->data_p;
    zone_status_00 = *puVar3;
    if (((~(uVar1 & 0x3cf) & zone_status_00 & 0x3cf) != 0) ||
       (((~zone_status_00 & uVar1) != 0 && ((uVar1 & 0x20) != 0)))) {
      send_zone_status_change_notif(ep_id_00,zone_status_00);
    }
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x1e8,
                "ias_zone_zone_status_change_handler","attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

