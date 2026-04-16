/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> ezb_zcl_thermostat_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ezb_zcl_thermostat_cluster_server_init(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  uint8_t *puVar4;
  int iVar5;
  uint16_t attr_id;
  byte bVar6;
  byte bVar7;
  undefined1 auStack_34 [4];
  zcl_cluster_template_t template;
  
  memcpy(auStack_34,&_LANCHOR0,0x14);
  pzVar1 = thermostat_srv_get_attr_desc(ep_id,0x21);
  pzVar2 = thermostat_srv_get_attr_desc(ep_id,0x22);
  pzVar3 = thermostat_srv_get_attr_desc(ep_id,attr_id);
  if (pzVar3 != (zcl_attr_desc_t *)0x0) {
    puVar4 = (uint8_t *)calloc(1,0x44);
    pzVar3->data_p = puVar4;
    if (puVar4 != (uint8_t *)0x0) {
      memset(puVar4 + 1,0,0x43);
      *puVar4 = ep_id;
      bVar6 = 0xff;
      if (pzVar1 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
        bVar6 = *pzVar1->data_p;
      }
      puVar4[3] = bVar6;
      bVar7 = 0xff;
      if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
        bVar7 = *pzVar2->data_p;
      }
      puVar4[4] = bVar7;
      if (bVar7 <= bVar6) {
        puVar4[1] = 0xff;
        puVar4[2] = 0xff;
        milli_timer_init(puVar4 + 0x34,thermostat_weekly_schedule_loop,puVar4);
        milli_timer_init(puVar4 + 0x24,thermostat_weekly_schedule_hold_on,puVar4);
        iVar5 = zcl_cluster_template_add(auStack_34);
        if (iVar5 == 0) {
          return;
        }
      }
    }
  }
  __assert_func(0,0,0,0);
  return;
}

