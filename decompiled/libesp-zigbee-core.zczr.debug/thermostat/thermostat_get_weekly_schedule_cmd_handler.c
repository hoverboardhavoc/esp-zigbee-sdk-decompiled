/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_get_weekly_schedule_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t thermostat_get_weekly_schedule_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t uVar1;
  _Bool _Var2;
  uint uVar3;
  undefined3 extraout_var;
  weekly_schedule_context_t *pwVar4;
  undefined3 extraout_var_00;
  ezb_zcl_status_t eVar5;
  char cVar6;
  weekly_schedule_graph_t *pwVar7;
  uint16_t uStack_26;
  undefined2 uStack_24;
  uint16_t uStack_22;
  ezb_zcl_thermostat_get_weekly_schedule_payload_t payload;
  uint16_t offset;
  
  uStack_22 = 0;
  uStack_24 = 0;
  if (packet == (zcl_packet_t *)0x0) {
    eVar5 = 0x80;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    eVar5 = 0x80;
  }
  else {
    af_read_le8(packet->payload,&uStack_22,(uint8_t *)&uStack_24);
    af_read_le8(packet->payload,&uStack_22,(uint8_t *)((int)&uStack_24 + 1));
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < uStack_22) {
      eVar5 = 0x80;
    }
    else {
      uVar1 = count_ones((uint8_t)uStack_24);
      if (CONCAT31(extraout_var,uVar1) == 1) {
        pwVar4 = thermostat_weekly_schedule_context_get((packet->header).dst_ep);
        uStack_26._0_1_ = 0;
        zmsg_append_bytes(rsp->payload,1,&uStack_26);
        uStack_26._0_1_ = (uint8_t)uStack_24;
        zmsg_append_bytes(rsp->payload,1,&uStack_26);
        uStack_26 = CONCAT11(uStack_26._1_1_,uStack_24._1_1_);
        zmsg_append_bytes(rsp->payload,1,&uStack_26);
        uVar3 = 0;
        do {
          if (6 < uVar3) {
            cVar6 = '\0';
_L0:
            uStack_26 = CONCAT11(uStack_26._1_1_,cVar6);
            zmsg_write_bytes(rsp->payload,0,1,&uStack_26);
            zcl_packet_setup_response(rsp,packet,0);
            return '\0';
          }
          _Var2 = thermostat_weekly_schedule_day_is_set((uint8_t)uStack_24,(uint8_t)uVar3);
          if (CONCAT31(extraout_var_00,_Var2) != 0) {
            pwVar7 = pwVar4->graph[uVar3];
            cVar6 = '\0';
            for (uVar3 = 0;
                ((pwVar7 != (weekly_schedule_graph_t *)0x0 && (uVar3 < pwVar7->num_of_transition))
                && (uVar3 < 10)); uVar3 = uVar3 + 1 & 0xff) {
              uStack_26 = pwVar7->transitions[uVar3].start_time;
              zmsg_append_bytes(rsp->payload,2,&uStack_26);
              if ((uStack_24 & 0x100) != 0) {
                uStack_26 = pwVar7->transitions[uVar3].heat_setpoint;
                zmsg_append_bytes(rsp->payload,2,&uStack_26);
              }
              if ((uStack_24 & 0x200) != 0) {
                uStack_26 = pwVar7->transitions[uVar3].cool_setpoint;
                zmsg_append_bytes(rsp->payload,2,&uStack_26);
              }
              cVar6 = cVar6 + '\x01';
            }
            goto _L0;
          }
          uVar3 = uVar3 + 1 & 0xff;
        } while( true );
      }
      eVar5 = 0x85;
    }
  }
  zcl_packet_setup_default_response(rsp,packet,eVar5);
  return eVar5;
}

