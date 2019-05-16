Simplify
========

Simplify allows particular fields to be hidden from the user interface. This
helps to de-clutter forms and present a more user-friendly experience to content
editors.

Different types of fields can be hidden with Simplify. Currently supported field
types include:

- Nodes
- Users
- Comments
- Taxonomy
- Blocks

Fields can be hidden globally or per field type.  
Globally hidden fields are hidden from all forms of that field type (e.g. a
field can be hidden from all node forms (Pages, Articles, etc.)).  
Fields can also be hidden more specifically based on their field type:

- Node fields per content type
- Comment fields per content type
- Taxonomy fields per vocabulary

(e.g. a field can be hidden from the Article content type but still be visible
on the Page content type).

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules.

- Visit the permissions page under Administration > Configuration > People >
  Permissions (admin/config/people/permissions) and choose which role(s) should
  be allowed to administer Simplify and which role(s) should be allowed to view
  hidden fields.

- Visit the configuration page under Administration > Configuration > User
  Interface > Simplify (admin/config/user-interface/simplify) and choose which
  fields you want to be hidden globally.

- Visit the content type edit pages under Administration > Structure > Content
  Types > [Content Type Name] > Edit (admin/structure/types/manage/[type]/edit)
  and choose which fields you want to be hidden per content type, and/or visit
  the taxonomy vocabulary edit pages under Administration > Structure >
  Taxonomy > Edit Vocabulary (admin/structure/taxonomy/[vocabulary]/edit) and
  choose which fields you want to be hidden per vocabulary.

Issues
------

Bugs and Feature requests should be reported in the Issue Queue:
https://github.com/backdrop-contrib/simplify/issues.

Current Maintainers
-------------------

- Peter Anderson (https://github.com/BWPanda).

Credits
-------

- Ported to Backdrop CMS by Peter Anderson (https://github.com/BWPanda).
- Originally written for Drupal by Mark Shust
  (https://www.drupal.org/u/markoshust).

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for
complete text.
