/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> identify.o -> identify_timer_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void identify_timer_handler(zcl_identify_timer_ctx_t *timer_ctx)

{
  zcl_attr_desc_t *pzVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 extraout_a1;
  uint16_t identify_value;
  undefined1 uVar4;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  if (timer_ctx == (zcl_identify_timer_ctx_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x7c,
                  "identify_timer_handler","timer_ctx");
  }
  else {
    pzVar1 = identify_srv_get_attr_desc(timer_ctx->ep_id,0);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
      identify_value = *pzVar1->data_p;
      if (identify_value != 0) {
        identify_value = identify_value - 1;
      }
      zcl_message_set_identify_attr_value((ushort)timer_ctx->ep_id,identify_value);
      return;
    }
  }
  uVar4 = 0x9c;
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/identify.c",0x7f
                        ,"identify_attr_desc");
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  iVar3 = zcl_packet_to_message(&uStack_44,uVar2);
  if (iVar3 == 0) {
    uStack_38._0_2_ = CONCAT11(uVar4,extraout_a1);
    uStack_34 = CONCAT31(uStack_34._1_3_,0xfe);
    uStack_3c = uVar2;
    zcl_core_action_schedule(10,&uStack_44);
  }
  return;
}

