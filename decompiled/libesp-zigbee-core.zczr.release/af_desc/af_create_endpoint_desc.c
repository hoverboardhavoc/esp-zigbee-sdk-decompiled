/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_create_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_ep_desc_t * af_create_endpoint_desc(af_ep_config_t *ep_config)

{
  uint8_t uVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  undefined2 uVar4;
  af_ep_desc_t *paVar5;
  
  paVar5 = (af_ep_desc_t *)calloc(1,0x20);
  if (paVar5 != (af_ep_desc_t *)0x0) {
    uVar1 = ep_config->ep_id;
    uVar2 = ep_config->app_profile_id;
    paVar5->ep_id = uVar1;
    paVar5->profile_id = uVar2;
    memset(&(paVar5->simple_desc).field_0x1,0,0xf);
    uVar3 = ep_config->app_device_id;
    (paVar5->simple_desc).ep_id = uVar1;
    (paVar5->simple_desc).app_profile_id = uVar2;
    (paVar5->simple_desc).app_device_id = uVar3;
    uVar4 = *(undefined2 *)&ep_config->field_0x6;
    paVar5->next = (af_ep_desc_s *)0x0;
    (paVar5->simple_desc).field_0x6 = (byte)uVar4 & 0xf;
  }
  return paVar5;
}

