/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_setpoint_raise_or_lower_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
thermostat_setpoint_raise_or_lower_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  ezb_zcl_status_t eVar1;
  uint uVar2;
  undefined3 extraout_var;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint8_t auStack_34 [4];
  ezb_zcl_thermostat_setpoint_raise_or_lower_payload_t payload;
  zcl_attr_desc_t *cool_desc;
  zcl_attr_desc_t *heat_desc;
  int16_t iStack_24;
  int16_t max_value;
  int16_t min_value;
  uint16_t offset;
  
  max_value = 0;
  iStack_24 = 0;
  heat_desc._2_2_ = 0;
  cool_desc = (zcl_attr_desc_t *)0x0;
  _payload = 0;
  auStack_34[0] = '\0';
  auStack_34[1] = '\0';
  if (packet == (zcl_packet_t *)0x0) {
    iVar5 = 0xfe;
    goto _L0;
  }
  if (rsp == (zcl_packet_t *)0x0) {
    iVar5 = 0xfe;
    goto _L0;
  }
  af_read_le8(packet->payload,(uint16_t *)&max_value,auStack_34);
  af_read_le8(packet->payload,(uint16_t *)&max_value,auStack_34 + 1);
  uVar2 = zcl_packet_payload_get_length(packet->payload);
  if (uVar2 < (ushort)max_value) {
    iVar5 = 0x80;
    goto _L0;
  }
  ep_id = (packet->header).dst_ep;
  thermostat_get_heat_cool_desc(ep_id,&cool_desc,(zcl_attr_desc_t **)&payload);
  if ((cool_desc == (zcl_attr_desc_t *)0x0) && (_payload == 0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/thermostat.c",0x449,
                  "thermostat_setpoint_raise_or_lower_cmd_handler","heat_desc || cool_desc");
_L0:
    iVar5 = 0;
  }
  else {
    if (cool_desc == (zcl_attr_desc_t *)0x0) goto _L0;
                    /* WARNING: Load size is inaccurate */
    iVar5 = (int)*cool_desc->data_p;
  }
  if (_payload == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (int)**(short **)(_payload + 8);
  }
  iVar3 = iVar5;
  if (auStack_34[0] == '\x01') {
    thermostat_get_cool_setpoint_limit(ep_id,&iStack_24,(int16_t *)((int)&heat_desc + 2));
    iVar5 = (char)auStack_34[1] * 10 + iVar6;
    iVar4 = (int)heat_desc._2_2_;
    if ((iVar5 <= heat_desc._2_2_) && (iVar4 = (int)iStack_24, iStack_24 <= iVar5)) {
      iVar4 = (int)(((((int)(char)auStack_34[1] & 0xffffU) * 0xa0000 >> 0x10) + iVar6) * 0x10000) >>
              0x10;
    }
  }
  else if (auStack_34[0] == '\x02') {
    thermostat_get_heat_setpoint_limit(ep_id,&iStack_24,(int16_t *)((int)&heat_desc + 2));
    iVar4 = (char)auStack_34[1] * 10 + iVar5;
    iVar3 = (int)heat_desc._2_2_;
    if ((iVar4 <= iVar3) && (iVar3 = (int)iStack_24, iVar3 <= iVar4)) {
      iVar3 = (int)(((((int)(char)auStack_34[1] & 0xffffU) * 0xa0000 >> 0x10) + iVar5) * 0x10000) >>
              0x10;
    }
    thermostat_get_cool_setpoint_limit(ep_id,&iStack_24,(int16_t *)((int)&heat_desc + 2));
    iVar5 = (char)auStack_34[1] * 10 + iVar6;
    iVar4 = (int)heat_desc._2_2_;
    if ((iVar5 <= heat_desc._2_2_) && (iVar4 = (int)iStack_24, iStack_24 <= iVar5)) {
      iVar4 = (int)(((((int)(char)auStack_34[1] & 0xffffU) * 0xa0000 >> 0x10) + iVar6) * 0x10000) >>
              0x10;
    }
  }
  else {
    iVar4 = iVar6;
    if (auStack_34[0] == '\0') {
      thermostat_get_heat_setpoint_limit(ep_id,&iStack_24,(int16_t *)((int)&heat_desc + 2));
      iVar6 = (char)auStack_34[1] * 10 + iVar5;
      iVar3 = (int)heat_desc._2_2_;
      if ((iVar6 <= iVar3) && (iVar3 = (int)iStack_24, iVar3 <= iVar6)) {
        iVar3 = (int)(((((int)(char)auStack_34[1] & 0xffffU) * 0xa0000 >> 0x10) + iVar5) * 0x10000)
                >> 0x10;
      }
    }
  }
  eVar1 = zcl_message_thermostat_setpoint(ep_id,auStack_34[0],(int16_t)iVar3,(int16_t)iVar4);
  iVar5 = CONCAT31(extraout_var,eVar1);
  if (iVar5 == 0) {
    thermostat_set_heat_cool_value(ep_id,auStack_34[0],(int16_t)iVar3,(int16_t)iVar4);
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,iVar5);
  return eVar1;
}

