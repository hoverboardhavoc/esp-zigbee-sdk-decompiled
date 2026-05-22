/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_app_secur.o -> apsme_transport_key_indication
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void apsme_transport_key_indication(apsme_transport_key_ind_t *ind)

{
  int iVar1;
  int iVar2;
  uint error;
  undefined4 uStack_1c;
  apsme_verify_key_req_t vk_req;
  
  if (ind->key_type == '\x01') {
    iVar1 = core_globals_get();
    if ((*(char *)(iVar1 + 0xcf8) == '\x01') || (iVar1 = nwk_secur_is_authenticated(), iVar1 != 0))
    {
      nwk_secur_set_key(&ind->field_2,(ind->field_2).nwk.key_seq);
    }
    iVar1 = core_globals_get();
    if (*(char *)(iVar1 + 0xcf8) != '\x01') {
      return;
    }
    nwk_pim_stop_fast_poll();
    iVar1 = nwk_is_device_zed();
    if ((iVar1 != 0) && (iVar1 = core_globals_get(), *(char *)(iVar1 + 0x9ee) == '\0')) {
      nwk_pim_stop_poll();
    }
    iVar1 = nwk_secur_switch_key((ind->field_2).nwk.key_seq);
    if (iVar1 == 0) {
      zdo_secur_finish_state(0);
      return;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_secur.c",0xef,
                  "apsme_transport_key_indication","(nwk_secur_switch_key(ind->nwk.key_seq)) == 0");
  }
  else if (ind->key_type != '\x04') {
    return;
  }
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xcf8) == '\x02') {
    iVar1 = aps_secur_is_addr_tc(ind);
    if (iVar1 == 0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_secur.c",0xf6,
                    "apsme_transport_key_indication","aps_secur_is_addr_tc(&ind->src_address)");
_L0:
      iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_app_secur.c",0x104,
                            "apsme_transport_key_indication",
                            "(apsme_verify_key_request(&vk_req)) == 0");
      if ((*(char *)(iVar1 + 8) == '\x04') &&
         (iVar2 = core_globals_get(), *(char *)(iVar2 + 0xcf8) == '\x03')) {
        nwk_pim_stop_fast_poll();
        if (*(byte *)(iVar1 + 9) == 0) {
          error = 0;
        }
        else {
          error = *(byte *)(iVar1 + 9) | 0x300;
        }
        zdo_secur_finish_state(error);
      }
      return;
    }
    iVar1 = aps_secur_get_key_pair_by_addr(ind);
    if ((iVar1 != 0) && ((*(ushort *)(iVar1 + 0x34) & 6) != 2)) {
      *(ushort *)(iVar1 + 0x34) = *(ushort *)(iVar1 + 0x34) & 0xfff9 | 2;
      memcpy((void *)(iVar1 + 0x12),&ind->field_2,0x10);
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0x9b8) = 0;
      iVar1 = core_globals_get();
      *(undefined1 *)(iVar1 + 0xcf8) = 3;
      vk_req.dst_address.field_0.u8[4] = '\x04';
      uStack_1c = *(undefined4 *)&(ind->src_address).field_0;
      vk_req.dst_address.field_0.u64._0_4_ = *(undefined4 *)((int)&(ind->src_address).field_0 + 4);
      iVar1 = apsme_verify_key_request(&uStack_1c);
      if (iVar1 != 0) goto _L0;
      iVar1 = core_globals_get();
      iVar2 = core_globals_get();
      milli_timer_start(iVar1 + 0xcfc,(*(ushort *)(iVar2 + 0x9ba) & 0x1f) * 1000);
    }
  }
  return;
}

