/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_on_with_recall_global_scene_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
on_off_cluster_on_with_recall_global_scene_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  int iVar2;
  zcl_attr_desc_t *unaff_s2;
  uint8_t unaff_s3;
  uint unaff_s4;
  uint8_t unaff_s5;
  
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1ba,
                  "on_off_cluster_on_with_recall_global_scene_cmd_handler","packet && rsp");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1be,
                  "on_off_cluster_on_with_recall_global_scene_cmd_handler","ep_desc");
  }
  else {
    unaff_s3 = (packet->header).dst_ep;
    unaff_s5 = (packet->header).cmd_id;
    iVar2 = af_get_ep_desc(unaff_s3);
    if (iVar2 == 0) goto _L0;
    unaff_s2 = on_off_srv_get_attr_desc(unaff_s3,0x4000);
    if (unaff_s2 == (zcl_attr_desc_t *)0x0) {
      unaff_s4 = 0x86;
      goto _L0;
    }
    if ((byte *)unaff_s2->data_p == (byte *)0x0) {
      unaff_s4 = 0x86;
      goto _L0;
    }
                    /* WARNING: Load size is inaccurate */
    unaff_s4 = (uint)*unaff_s2->data_p;
    if (unaff_s4 != 0) {
      unaff_s4 = 0xfe;
      goto _L0;
    }
  }
  zcl_scenes_recall_scene(packet,0,0,0);
  *(undefined1 *)unaff_s2->data_p = 1;
  on_off_process_transition(unaff_s3,unaff_s5,'\x01',0,0);
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,unaff_s4);
  return eVar1;
}

