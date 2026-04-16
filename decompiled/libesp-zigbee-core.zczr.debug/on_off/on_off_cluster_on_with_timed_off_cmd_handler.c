/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_cluster_on_with_timed_off_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
on_off_cluster_on_with_timed_off_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  uint8_t cmd_id;
  ezb_zcl_status_t eVar1;
  int iVar2;
  uint uVar3;
  zcl_attr_desc_t *pzVar4;
  zcl_attr_desc_t *pzVar5;
  zcl_attr_desc_t *pzVar6;
  char cVar7;
  uint8_t on_off;
  ushort uVar8;
  uint16_t x;
  ushort uVar9;
  ushort uVar10;
  uint16_t uStack_28;
  uint16_t uStack_26;
  uint16_t off_wait_time;
  uint16_t on_time;
  uint8_t on_off_control;
  uint16_t offset;
  
  on_time = 0;
  off_wait_time._1_1_ = 0;
  uStack_26 = 0;
  uStack_28 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1e5,
                  "on_off_cluster_on_with_timed_off_cmd_handler","packet && rsp");
_L0:
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1e9,
                  "on_off_cluster_on_with_timed_off_cmd_handler","ep_desc");
  }
  else {
    ep_id = (packet->header).dst_ep;
    cmd_id = (packet->header).cmd_id;
    iVar2 = af_get_ep_desc(ep_id);
    if (iVar2 == 0) goto _L0;
    af_read_le8(packet->payload,&on_time,(uint8_t *)((int)&off_wait_time + 1));
    af_read_le16(packet->payload,&on_time,&uStack_26);
    af_read_le16(packet->payload,&on_time,&uStack_28);
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < on_time) {
      return 0x80;
    }
    pzVar4 = on_off_srv_get_attr_desc(ep_id,0);
    pzVar5 = on_off_srv_get_attr_desc(ep_id,0x4001);
    pzVar6 = on_off_srv_get_attr_desc(ep_id,0x4002);
    if (pzVar4 != (zcl_attr_desc_t *)0x0) {
      if ((pzVar5 != (zcl_attr_desc_t *)0x0) && (pzVar6 != (zcl_attr_desc_t *)0x0)) {
        if (pzVar4 == (zcl_attr_desc_t *)0x0) {
          cVar7 = '\0';
        }
        else if ((char *)pzVar4->data_p == (char *)0x0) {
          cVar7 = '\0';
        }
        else {
                    /* WARNING: Load size is inaccurate */
          cVar7 = *pzVar4->data_p;
        }
        if ((ushort *)pzVar5->data_p == (ushort *)0x0) {
          uVar9 = 0;
        }
        else {
                    /* WARNING: Load size is inaccurate */
          uVar9 = *pzVar5->data_p;
        }
        if ((ushort *)pzVar6->data_p == (ushort *)0x0) {
          uVar8 = 0;
        }
        else {
                    /* WARNING: Load size is inaccurate */
          uVar8 = *pzVar6->data_p;
        }
        if (((off_wait_time._1_1_ & 1) != 0) && (cVar7 == '\0')) {
          return 0xfe;
        }
        uVar10 = uStack_28;
        if ((uVar8 == 0) || (cVar7 != '\0')) {
          x = uStack_26;
          if (uStack_26 < uVar9) {
            x = uVar9;
          }
          on_off = '\x01';
        }
        else {
          if (uVar8 < uStack_28) {
            uVar10 = uVar8;
          }
          x = 0;
          on_off = '\0';
        }
        on_off_process_transition(ep_id,cmd_id,on_off,x,uVar10);
        eVar1 = zcl_packet_setup_default_response(rsp,packet,0);
        if (uStack_26 == 0xffff) {
          return eVar1;
        }
        if (uStack_28 == 0xffff) {
          return eVar1;
        }
        on_off_timer_start(ep_id,100);
        return eVar1;
      }
      goto _L0;
    }
  }
  __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x1f5,
                "on_off_cluster_on_with_timed_off_cmd_handler","on_off_attr_desc");
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,0x8c);
  return eVar1;
}

