/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> thermostat_setpoint_raise_or_lower_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void thermostat_setpoint_raise_or_lower_cmd_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uStack_34;
  int iStack_30;
  int iStack_2c;
  short sStack_26;
  short sStack_24;
  ushort auStack_22 [3];
  
  auStack_22[0] = 0;
  sStack_24 = 0;
  sStack_26 = 0;
  iStack_2c = 0;
  iStack_30 = 0;
  uStack_34 = 0;
  if (param_1 == 0) {
    iVar5 = 0xfe;
    goto _L0;
  }
  if (param_2 == 0) {
    iVar5 = 0xfe;
    goto _L0;
  }
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_34);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_34 + 1);
  uVar2 = zcl_packet_payload_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar2 < auStack_22[0]) {
    iVar5 = 0x80;
    goto _L0;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  thermostat_get_heat_cool_desc(uVar1,&iStack_2c,&iStack_30);
  if ((iStack_2c == 0) && (iStack_30 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/thermostat.c",0x449,
                  "thermostat_setpoint_raise_or_lower_cmd_handler","heat_desc || cool_desc");
_L0:
    iVar5 = 0;
  }
  else {
    if (iStack_2c == 0) goto _L0;
    iVar5 = (int)**(short **)(iStack_2c + 8);
  }
  if (iStack_30 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = (int)**(short **)(iStack_30 + 8);
  }
  iVar3 = iVar5;
  if ((char)uStack_34 == '\x01') {
    thermostat_get_cool_setpoint_limit(uVar1,&sStack_24,&sStack_26);
    iVar5 = uStack_34._1_1_ * 10 + iVar6;
    iVar4 = (int)sStack_26;
    if ((iVar5 <= sStack_26) && (iVar4 = (int)sStack_24, sStack_24 <= iVar5)) {
      iVar4 = (int)(((((int)uStack_34._1_1_ & 0xffffU) * 0xa0000 >> 0x10) + iVar6) * 0x10000) >>
              0x10;
    }
  }
  else if ((char)uStack_34 == '\x02') {
    thermostat_get_heat_setpoint_limit(uVar1,&sStack_24,&sStack_26);
    iVar4 = uStack_34._1_1_ * 10 + iVar5;
    iVar3 = (int)sStack_26;
    if ((iVar4 <= iVar3) && (iVar3 = (int)sStack_24, iVar3 <= iVar4)) {
      iVar3 = (int)(((((int)uStack_34._1_1_ & 0xffffU) * 0xa0000 >> 0x10) + iVar5) * 0x10000) >>
              0x10;
    }
    thermostat_get_cool_setpoint_limit(uVar1,&sStack_24,&sStack_26);
    iVar5 = uStack_34._1_1_ * 10 + iVar6;
    iVar4 = (int)sStack_26;
    if ((iVar5 <= sStack_26) && (iVar4 = (int)sStack_24, sStack_24 <= iVar5)) {
      iVar4 = (int)(((((int)uStack_34._1_1_ & 0xffffU) * 0xa0000 >> 0x10) + iVar6) * 0x10000) >>
              0x10;
    }
  }
  else {
    iVar4 = iVar6;
    if ((char)uStack_34 == '\0') {
      thermostat_get_heat_setpoint_limit(uVar1,&sStack_24,&sStack_26);
      iVar6 = uStack_34._1_1_ * 10 + iVar5;
      iVar3 = (int)sStack_26;
      if ((iVar6 <= iVar3) && (iVar3 = (int)sStack_24, iVar3 <= iVar6)) {
        iVar3 = (int)(((((int)uStack_34._1_1_ & 0xffffU) * 0xa0000 >> 0x10) + iVar5) * 0x10000) >>
                0x10;
      }
    }
  }
  iVar5 = zcl_message_thermostat_setpoint(uVar1,(char)uStack_34,iVar3,iVar4);
  if (iVar5 == 0) {
    thermostat_set_heat_cool_value(uVar1,(char)uStack_34,iVar3,iVar4);
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,iVar5);
  return;
}

