/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> poll_control.o -> poll_control_cluster_srv_check_in_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: fast_poll_timeout */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
poll_control_cluster_srv_check_in_rsp_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  zcl_attr_desc_t *pzVar3;
  undefined4 uVar4;
  uint16_t uStack_16;
  uint16_t uStack_14;
  uint16_t offset;
  uint16_t fast_poll_timeout;
  _Bool start_fast_poll;
  
  offset._1_1_ = '\0';
  uStack_14 = 0;
  uStack_16 = 0;
  if (packet != (zcl_packet_t *)0x0) {
    if (rsp == (zcl_packet_t *)0x0) {
      uVar4 = 0xfe;
      goto _L0;
    }
    af_read_le8(packet->payload,&uStack_16,(uint8_t *)((int)&offset + 1));
    af_read_le16(packet->payload,&uStack_16,&uStack_14);
    if (uStack_16 != 0) {
      uVar4 = 0x80;
      goto _L0;
    }
    _Var2 = poll_control_source_is_exist_in_bind_table
                      ((packet->header).src_ep,(packet->header).src_addr.u.short_addr);
    if (CONCAT31(extraout_var,_Var2) == 0) {
      uVar4 = 1;
      goto _L0;
    }
    if (offset._1_1_ == '\0') {
      uVar4 = 0;
      goto _L0;
    }
    pzVar3 = poll_control_srv_get_attr_desc((packet->header).dst_ep,3);
    if (pzVar3 != (zcl_attr_desc_t *)0x0) {
      if (uStack_14 == 0) {
                    /* WARNING: Load size is inaccurate */
        uStack_14 = *pzVar3->data_p;
      }
      pzVar3 = poll_control_srv_get_attr_desc((packet->header).dst_ep,6);
                    /* WARNING: Load size is inaccurate */
      if ((pzVar3 == (zcl_attr_desc_t *)0x0) || (uStack_14 <= *pzVar3->data_p)) {
        poll_control_start_fast_poll((packet->header).dst_ep,(uint)uStack_14 * 0xfa);
        uVar4 = 0;
      }
      else {
        uVar4 = 0x85;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/poll_control.c",0x180,
                  "poll_control_cluster_srv_check_in_rsp_handler",0x1026c);
  }
  uVar4 = 0xfe;
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar1;
}

