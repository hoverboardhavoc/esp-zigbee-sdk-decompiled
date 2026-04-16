/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> identify.o -> identify_timer_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void identify_timer_handler(zcl_identify_timer_ctx_t *timer_ctx)

{
  uint8_t ep_id;
  int iVar1;
  zcl_attr_desc_t *pzVar2;
  uint16_t attr_id;
  uint16_t in_a1;
  uint16_t extraout_a1;
  short asStack_12 [5];
  
  if (timer_ctx != (zcl_identify_timer_ctx_t *)0x0) goto _L22;
  do {
    timer_ctx = (zcl_identify_timer_ctx_t *)__assert_func(0,0,0,0);
    in_a1 = extraout_a1;
_L22:
    pzVar2 = identify_srv_get_attr_desc(timer_ctx->ep_id,in_a1);
  } while (pzVar2 == (zcl_attr_desc_t *)0x0);
                    /* WARNING: Load size is inaccurate */
  asStack_12[0] = *pzVar2->data_p;
  if (asStack_12[0] != 0) {
    asStack_12[0] = asStack_12[0] + -1;
  }
  ep_id = timer_ctx->ep_id;
  iVar1 = ezb_zcl_set_attr_value(ep_id,3,1,0,0,asStack_12,0);
  if (iVar1 == 0) {
    pzVar2 = identify_srv_get_attr_desc(ep_id,attr_id);
    zcl_message_notify_attr_value(ep_id,3,1,pzVar2);
  }
  return;
}

