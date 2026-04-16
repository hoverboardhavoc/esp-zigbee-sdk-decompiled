/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> thermostat.o -> zcl_message_thermostat_setpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
zcl_message_thermostat_setpoint(uint8_t ep_id,uint8_t mode,int16_t heat,int16_t cool)

{
  short local_20;
  undefined2 uStack_1e;
  ezb_zcl_thermostat_setpoint_message_t message;
  
  _local_20 = CONCAT22(0x201,(ushort)ep_id << 8);
  message.info._0_4_ = (uint)mode << 0x10;
  message.in._0_2_ = heat;
  message.info._4_2_ = cool;
  message.in.setpoint_cool = 0xfe;
  zcl_core_action_schedule(0x37,&local_20);
  if ((ezb_zcl_status_t)message.in.setpoint_cool == 0xfe) {
    message.in.setpoint_cool._0_1_ = '\0';
  }
  return (ezb_zcl_status_t)message.in.setpoint_cool;
}

