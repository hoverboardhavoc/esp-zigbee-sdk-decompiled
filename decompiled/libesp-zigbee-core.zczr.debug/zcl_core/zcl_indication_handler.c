/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_indication_handler(af_data_ind_t *arg)

{
  int unaff_s0;
  _Bool _Var1;
  zcl_status_t zVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  auStack_38 = (undefined1  [4])0x0;
  packet.header.src_addr._0_4_ = 0;
  packet.header.src_addr.u._2_4_ = 0;
  packet.header._8_4_ = 0;
  packet.header.dst_addr.u._0_2_ = 0;
  packet.header.dst_addr.u._2_2_ = 0;
  packet.header.dst_addr.u._4_4_ = 0;
  packet.header.src_ep = '\0';
  packet.header.dst_ep = '\0';
  packet.header.cluster_id = 0;
  packet.header.profile_id = 0;
  packet.header.fc = '\0';
  packet.header._27_1_ = 0;
  packet.header.manuf_code = 0;
  packet.header.tsn = '\0';
  packet.header.rssi = '\0';
  packet.header.cmd_id = '\0';
  packet.header._33_1_ = 0;
  packet._34_2_ = 0;
  if (arg == (af_data_ind_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_core.c",0x96,
                  "zcl_indication_handler",&_L0);
_L0:
    iVar3 = core_globals_get();
    if ((*(int *)(iVar3 + 0xd18) != 0) &&
       (_Var1 = zcl_raw_frame_handler((zcl_packet_t *)auStack_38), CONCAT31(extraout_var,_Var1) != 0
       )) goto _L0;
    unaff_s0 = zcl_packet_is_acceptable(auStack_38);
    if (unaff_s0 == 0) {
      zVar2 = zcl_packet_handler((zcl_packet_t *)auStack_38);
      unaff_s0 = CONCAT31(extraout_var_00,zVar2);
      if (unaff_s0 == 0) goto _L0;
    }
  }
  else {
    unaff_s0 = zcl_packet_init_with_msg(auStack_38,arg);
    if (unaff_s0 == 0) goto _L0;
    unaff_s0 = 0xfe;
  }
  if (unaff_s0 != 0xfe) {
    unaff_s0 = zcl_packet_send_default_response(auStack_38,unaff_s0);
  }
_L0:
  return (zcl_status_t)unaff_s0;
}

