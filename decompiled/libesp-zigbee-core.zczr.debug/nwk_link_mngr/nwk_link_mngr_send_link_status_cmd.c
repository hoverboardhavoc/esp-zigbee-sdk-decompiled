/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_send_link_status_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_link_mngr_send_link_status_cmd(void)

{
  uint8_t mac_iface;
  _Bool _Var1;
  ezb_shortaddr_t eVar2;
  undefined3 extraout_var;
  zmsg_t *msg;
  int iVar3;
  int iVar4;
  
  _Var1 = nwk_is_router_started();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_link_mngr.c",0xea,
                  "nwk_link_mngr_send_link_status_cmd","nwk_is_router_started()");
_L0:
    iVar3 = core_globals_get();
    iVar4 = core_globals_get();
    nwk_link_mngr_start_timer((milli_timer_t *)(iVar3 + 0xae4),*(uint8_t *)(iVar4 + 0xa24),0x40);
  }
  else {
    msg = (zmsg_t *)zmsg_alloc(0x27);
    if (msg != (zmsg_t *)0x0) {
      iVar3 = core_globals_get();
      mac_iface = *(uint8_t *)(iVar3 + 0xb06);
      iVar3 = core_globals_get();
      eVar2 = *(ezb_shortaddr_t *)(iVar3 + 0xb04);
      iVar3 = core_globals_get();
      eVar2 = nwk_link_mngr_prepare_link_status_command(msg,mac_iface,eVar2,'\x1a');
      *(ezb_shortaddr_t *)(iVar3 + 0xb04) = eVar2;
      nwk_fwd_send_msg_delayed(msg,0);
    }
    iVar3 = core_globals_get();
    if (*(short *)(iVar3 + 0xb04) == 0) {
      iVar3 = core_globals_get();
      iVar3 = nwk_mm_get_next_router_iface(iVar3 + 0xb06);
      if (iVar3 != 0) goto _L0;
    }
    iVar3 = core_globals_get();
    nwk_link_mngr_start_timer((milli_timer_t *)(iVar3 + 0xae4),'\0',0x40);
  }
  return;
}

