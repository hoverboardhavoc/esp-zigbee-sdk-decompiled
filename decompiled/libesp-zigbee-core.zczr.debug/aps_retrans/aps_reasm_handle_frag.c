/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_reasm_handle_frag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void aps_reasm_handle_frag(aps_header_t *aps_hdr,zmsg_t *msg)

{
  byte bVar1;
  int iVar2;
  aps_reasm_ent_t *ent;
  
  if ((char)aps_hdr->fcf < '\0') {
    bVar1 = (aps_hdr->ext_hdr).block_nr;
    if (bVar1 != 0) {
      if ((((aps_hdr->ext_hdr).ext_fcf & 3) != 2) && (bVar1 < 2)) goto _L0;
      if ((aps_hdr->fcf & 3) == 0) {
        iVar2 = core_globals_get();
        ent = aps_reasm_ent_find((aps_rx_context_t *)(iVar2 + 0x458),(aps_hdr->addr_info).src_addr,
                                 aps_hdr->aps_cntr);
        if (ent != (aps_reasm_ent_t *)0x0) {
_L0:
          aps_reasm_ent_input(ent,aps_hdr,msg);
          return;
        }
        iVar2 = core_globals_get();
        ent = aps_reasm_ent_new((aps_rx_context_t *)(iVar2 + 0x458));
        if (ent != (aps_reasm_ent_t *)0x0) {
          iVar2 = core_globals_get();
          aps_reasm_ent_init(ent,*(uint8_t *)(iVar2 + 2));
          ent->src_addr = (aps_hdr->addr_info).src_addr;
          ent->aps_cntr = aps_hdr->aps_cntr;
          aps_rx_window_init(&ent->w,(ent->w).slot_nr);
          milli_timer_start(&ent->tm,0x640);
          goto _L0;
        }
      }
    }
    if (msg != (zmsg_t *)0x0) {
      zmsg_free(msg);
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x25b,
                  "aps_reasm_handle_frag","aps_fcf_has_ext_hdr(aps_hdr->fcf)");
_L0:
    aps_handle_datagram();
  }
  return;
}

