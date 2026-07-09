/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_message_notify_manuf_spec_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint zcl_message_notify_manuf_spec_cmd(int param_1)

{
  uint uVar1;
  uint uVar2;
  size_t __size;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  uint uStack_18;
  undefined2 uStack_12;
  
  uStack_12 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  iStack_24 = 0;
  uStack_20 = 0;
  pvStack_1c = (void *)0x0;
  uStack_18 = 0;
  uVar2 = zcl_packet_to_message(&uStack_2c,param_1);
  if (uVar2 == 0) {
    iStack_24 = param_1;
    __size = zcl_packet_payload_get_length(*(undefined4 *)(param_1 + 0x24));
    uStack_20 = CONCAT22(uStack_20._2_2_,(short)__size);
    pvStack_1c = calloc(1,__size);
    if ((pvStack_1c == (void *)0x0) && (__size != 0)) {
      uVar2 = 0x89;
    }
    else {
      if (__size == 0) {
        pvStack_1c = (void *)0x0;
      }
      af_read_bytes(*(undefined4 *)(param_1 + 0x24),&uStack_12,__size,pvStack_1c);
      uStack_18 = CONCAT31(uStack_18._1_3_,0xfe);
      zcl_core_action_schedule(9,&uStack_2c);
      uVar1 = uStack_18 & 0xff;
      if ((uStack_18 & 0xff) == 0xfe) {
        uVar1 = uVar2;
      }
      uVar2 = uVar1;
      zcl_packet_send_default_response(param_1,uVar2);
    }
  }
  if (pvStack_1c != (void *)0x0) {
    mm_free();
  }
  return uVar2;
}

