/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_create_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_ep_desc_t * af_create_endpoint_desc(af_ep_config_t *ep_config)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  uint16_t uVar6;
  uint16_t uVar7;
  af_ep_desc_t *paVar8;
  af_ep_config_t *paVar9;
  
  paVar8 = (af_ep_desc_t *)calloc(1,0x1c);
  if (paVar8 != (af_ep_desc_t *)0x0) {
    paVar8->ep_id = ep_config->ep_id;
    paVar8->profile_id = ep_config->app_profile_id;
    paVar9 = (af_ep_config_t *)calloc(1,8);
    if (paVar9 == (af_ep_config_t *)0x0) {
      mm_free(paVar8);
      paVar8 = (af_ep_desc_t *)0x0;
    }
    else {
      uVar1 = ep_config->field_0x1;
      uVar6 = ep_config->app_profile_id;
      uVar2 = *(undefined1 *)((int)&ep_config->app_profile_id + 1);
      uVar7 = ep_config->app_device_id;
      uVar3 = *(undefined1 *)((int)&ep_config->app_device_id + 1);
      uVar4 = ep_config->field_0x6;
      uVar5 = ep_config->field_0x7;
      paVar9->ep_id = ep_config->ep_id;
      paVar9->field_0x1 = uVar1;
      *(char *)&paVar9->app_profile_id = (char)uVar6;
      *(undefined1 *)((int)&paVar9->app_profile_id + 1) = uVar2;
      *(char *)&paVar9->app_device_id = (char)uVar7;
      *(undefined1 *)((int)&paVar9->app_device_id + 1) = uVar3;
      paVar9->field_0x6 = uVar4;
      paVar9->field_0x7 = uVar5;
      paVar8->ep_config = paVar9;
      paVar8->next = (af_ep_desc_s *)0x0;
    }
  }
  return paVar8;
}

